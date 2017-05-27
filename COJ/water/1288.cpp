#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string t;
	string str;
	int sz;
	while(cin>>n>>t && n){

        cin.ignore();//为了忽略掉前面的回车或空格，方便后面读取整行字符串
        getline(cin,str);//读取带空格的字符串，以回车结束输入
        sz = str.size();
        if(sz==n){
            cout<<str<<endl;
        }else if(sz<n){
            for(int i=0;i<n-sz;i++){
                cout<<t;
            }
            cout<<str<<endl;
        }else{
            for(int i=sz-n;i<sz;i++){
                cout<<str[i];
            }
            cout<<endl;
        }
	}
	return 0;
}
