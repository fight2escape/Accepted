#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string t;
	string str;
	int sz;
	while(cin>>n>>t && n){
        cin.ignore();
        getline(cin,str);
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
