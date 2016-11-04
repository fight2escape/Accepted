#include <iostream>
#include <string>

using namespace std;
int main(){
	string a;
	int len;
	while(cin>>a){
		len = a.size();
		if(len<=1){
			break;
		}
		cout<<a[len-2]<<endl;
	}
	return 0;	
}
