#include <iostream>
#include <string>
using namespace std;
int main(){
	int t,n;
	string arr[26];
	int size[26][2]={0};
	int i=0;
	char exp[100][100]={'0'};
	while(1){	
		cin>>t>>n;
		if(t==0 || n==0){break;}
		while(t--){
			cin>>arr[i]>>size[i][0]>>size[i][1];
		}
		while(n--){
			cin>>exp[i];
		}

	}
	return 0;
}