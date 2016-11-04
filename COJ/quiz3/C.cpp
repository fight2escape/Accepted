#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool compare(int a,int b){
	return a<b;
}
int a[100005];
int main(){
	int t;
	cin>>t;
	int n;
	int i,j,k;
	int temp;
	bool flag;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n,compare);
		flag = false;
		for(i=n-1;i>1;i--){
			if(a[i]<(a[i-1]+a[i-2])){	
				cout<<a[i]+a[i-1]+a[i-2]<<endl;
				flag = true;
				break;
				
			}
		}
		if(flag == false){
			cout<<"OrzYW"<<endl;
		}
	}
	return 0;	
}
