#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void toHtml(string line);
void getHeader(string line);
void getUl(string line);
void getp(string line);
void inside(string &line,int n=0);
void getLine(string &line,int n=1);
string getEm(string line,int &n);
string getLink(string line,int &n);


// 总的输出结果
string text[105] = {};
// 结果下标
int num = 0;

// 获取可能的超链接
string getLink(string line,int &n){
	if (line.size() < 1 || line.empty()) {
		return "[";
	}
	// 新建下标，因为传入时line[n]指向第一个'_'，需加1
	int ai = n+1;
	// 分别缓存[]和()中的字符
	string atext = "";
	string alink = "";
	// 判断前面的[]是否成对
	bool flag2 = true;
	// 匹配']'
	while(line[ai]!=']'){
		// 缓存中间的字符串
		atext += line[ai];
		// 如果下一个字符是结束符，代表当前字符是最后一个字符
		// 没有找到成对标签，设为false并结束
		ai++;
		if(line[ai]=='\0'){
			flag2 = false;
			break;
		}
	}
	// 处理可能的斜体
	inside(atext);
	// 如果前面没有匹配到，或者下一个字符不是'('
	if(!flag2 || line[ai+1]!='('){
		// 记录下传进来之前line[n]指向的值返回
		char first = line[n];
		// 因为匹配失败，ai已经指向'\0'结束符，需要向前一位防止出错
		n = ai-1;
		return first+atext;
	}
	// 能走到这说明[]匹配成功，且ai++后指向的是'('
	ai++;
	// 继续指向下一个
	ai++;
	// 判断后面的()是否成对
	bool flag = true;
	// 匹配')'
	while(line[ai]!=')'){
		// 缓存中间的字符串
		alink += line[ai];
		// 如果下一个字符是结束符，代表当前字符是最后一个字符
		// 没有找到成对标签，设为false并结束
		ai++;
		if(line[ai]=='\0'){
			flag = false;
			break;
		}
	}
	if(flag){
		// 返回正确的解析结果
		n = ai;
		return "<a href=\""+alink+"\">"+atext+"</a>";
	}else{
		// 如果不是成对的，说明已经到了字符串的末尾
		// 且指向的是'\0'结束符，需要向前一位才是末尾元素
		// 调用者需要继续向下查询才不会导致越界出错
		n = ai-1;
		return "["+atext+"]("+alink;
	}
}

// 处理可能的斜体
string getEm(string line,int &n){
	if (line.size() < 1 || line.empty()) {
		return "_";
	}
	// 局部变量做下标
	int ei;
	// 判断是否是成对标签
	bool flag;
	// 存储可能变为斜体的那段字符
	string emtext="";
	// 因为传入时line[n]指向第一个'_'，需加1
	ei = n+1;
	flag = true;
	// 如果遇到第二个'_'则停止
	while(line[ei]!='_'){
		// 记下中间的字符
		emtext += line[ei++];
		// 如果下一个字符是结束符，代表当前字符是最后一个字符
		// 没有找到成对标签，设为false并结束
		if(line[ei]=='\0'){
			flag = false;
			break;
		}
	}
	// 处理中间的字符串中可能嵌套的超链接
	inside(emtext);
	if(flag){
		// 如果是成对的，当前的line[ei]指向的是'_'后面的第一个字符
		n = ei;
		return "<em>" + emtext + "</em>";
	}else{
		// 如果不是成对的，说明已经到了字符串的末尾
		// 且指向的是'\0'结束符，需要向前一位才是末尾元素
		// 调用者需要继续向下查询才不会导致越界出错
		n = ei-1;
		return  "_" + emtext;
	}
	
}

// 处理行内元素，斜体和超链接
void inside(string &line, int n) {
	if (line.size() >= 1 && !line.empty()) {
		string tmp;
		// 逐个字符扫描直到末尾
		while (line[n] != '\0') {
			switch (line[n]) {
				// 可能是斜体
			case '_':
				tmp += getEm(line, n);
				break;
				// 可能是超链接
			case '[':
				tmp += getLink(line, n);
				break;
				// 其他的可以直接入缓存中
			default:
				tmp += line[n];
			}
			// 下一个字符
			n++;
		}
		// 处理完毕返回
		line = tmp;
	}
}

// 清理无用空格
void getLine(string &line,int n){
	// 忽略掉空格
	while(line[n]==' '){
		n++;
	}
	// 然后通过中间变量来获取后面的有效字符
	int t=0;
	string tmp="";
	while(line[n]!='\0'){
		tmp += line[n++];
	}
	// 处理数据
	inside(tmp);
	// 因为是引用，直接赋值修改
	line = tmp;
}

// 处理段落
void getp(string line){
	// 如果是空行则跳过不处理
	if(line != "\0"){
		// 进行行内元素的处理
		inside(line);
		// 下面这两个貌似已经包含在上面
		// existLink(line);
		// existEm(line);
		// 多行文本只能有一对标签，所以得判断上一行是否也是段落
		int len = 0;
		// 获取上一行长度
		if(num>0){
			len = text[num-1].size();
		}
		// 如果是以</p>结尾的话，得去掉该结束标签，添加在当前行末尾
		if(len && text[num-1][len-1]=='>'
				&& text[num-1][len-2]=='p' 
				&& text[num-1][len-3]=='/' 
				&& text[num-1][len-4]=='<'){
			// 置为空
			text[num-1][len-4] = NULL;
			text[num-1][len-3] = NULL;
			text[num-1][len-2] = NULL;
			text[num-1][len-1] = NULL;
			// 当前行就不必添加开始标签
			line = line + "</p>";
		}else{
			// 否则直接添加成对标签即可
			line = "<p>" + line + "</p>";
		}
		// 将最后结果添加到输出中
		text[num++] = line;
	}
}
// 处理无序列表
void getUl(string line){
	int n = 1;
	// 先判断前面一行是否也是列表
	if(num>1 && text[num-1]=="</ul>"){
		// 如果后面没有空格则是段落
		if (line[n] == ' ') {
			// 数据的处理
			getLine(line);
			// 如果是，则将本行结果赋给上一行
			text[num - 1] = "<li>" + line + "</li>";
			// 并在当前行上加上结束标签
			text[num++] = "</ul>";
		}
		else {
			getp(line);
		}
	}else {
		// 如果后面没有空格则是段落
		if (line[n] == ' ') {
			// 否则，在当前行加上开始标签
			text[num++] = "<ul>";
			// 处理数据
			getLine(line);
			// 将结果赋给下一行
			line = "<li>" + line + "</li>";
			text[num++] = line;
			// 再再接下去的一行加上结束标签
			text[num++] = "</ul>";
		}
		else {
			getp(line);
		}
	}
}

// 处理标题
void getHeader(string line){
	// 前后两个标签
	int n = 1;
	string header;
	string header2;
	// 判断是几级标题
	while(line[n]=='#'){
		n++;
	}
	switch(n){
		case 1: header="<h1>";header2="</h1>";break;
		case 2: header="<h2>";header2="</h2>";break;
		case 3: header="<h3>";header2="</h3>";break;
		case 4: header="<h4>";header2="</h4>";break;
		case 5: header="<h5>";header2="</h5>";break;
		case 6: header="<h6>";header2="</h6>";break;
	}
	// 如果后面没有空格则是段落
	if(line[n]==' '){
		// 清理无用空格
		getLine(line,n);
		// 生成正确格式的html
		line = header+line+header2;
		// 加入到总输出中
		text[num++] = line;
	}
	else {
		getp(line);
	}
}

// 处理的开始，先查看块状的，以首元素为参考
void toHtml(string line){
	switch(line[0]){
		case '#':
			// 处理标题
			getHeader(line);break;
		case '*':
			// 处理无序列表
			getUl(line);break;
		default:
			// 处理段落
			getp(line);
	}
}

int main(){
	// 逐行输入同时做处理输出
	string line;
	while(getline(cin,line)){
		toHtml(line);	
		// 输出所有的结果
		for(int i=0;i<num;i++){
			cout<<text[i]<<endl;
		}
	}
	return 0;
}
