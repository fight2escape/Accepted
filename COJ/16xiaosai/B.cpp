/*
思路：
要求输入字符串包括空格，需要用getline()解决，并判断首个字符是否是结束符。
之后双重循环逐个对字符作判断，设置一个time数组，保存各个字符的出现次数，出现一次就自增。
坑：
提交后PE，最后心如死灰，随便尝试了下，最后一行后不能有换行，完美AC，精彩，什么破题
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	string s;
	int time[6];
	int sz;
	int i,j,k;

	while(getline(cin,s) && s[0]!='#'){
		getline(cin,str);
		for(i=0;i<s.size();i++){
			time[i] = 0;
			for(j=0;j<str.size();j++){
				if(s[i]==str[j]){
					time[i]++;
				}
			}
		}
		for(i=0;i<s.size();i++){
            if(i>0){
                cout<<endl;
            }
			cout<<s[i]<<" "<<time[i];
		}
	}
	return 0;
}
