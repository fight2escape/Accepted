#include <iostream>
using namespace std;
int main(){
	int a,b,n;
	int r;
	int f[10000] = {0};
	int res[10000] = {0},k=0;
	f[1] = 1;f[2] = 1;
	while(cin>>a>>b>>n && a+b+n){
		for(int i=3;i<10000;i++){
			f[i] = (a*f[i-1] + b*f[i-2])%7;
			//cout<<i<<':'<<f[i]<<endl;
			if(i>3 && f[i-1]==1 && f[i-2]==1){
				r = i-3;				
				f[0] = f[r];
				break;
			}		
		}
		//cout<<"r:"<<r<<endl;
		res[k] = f[n%r];
		k++;
	}
	for(int j=0;j<k;j++){
		cout<<res[j]<<endl;
	}
	return 0;
}