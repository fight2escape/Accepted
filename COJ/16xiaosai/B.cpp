/*
˼·��
Ҫ�������ַ��������ո���Ҫ��getline()��������ж��׸��ַ��Ƿ��ǽ�������
֮��˫��ѭ��������ַ����жϣ�����һ��time���飬��������ַ��ĳ��ִ���������һ�ξ�������
�ӣ�
�ύ��PE������������ң���㳢�����£����һ�к����л��У�����AC�����ʣ�ʲô����
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
