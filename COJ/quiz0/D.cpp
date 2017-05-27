#include<iostream>
using namespace std;
int main(){
	int t,n,i=0;
	int sta[40]={0};
	int x[43]={0};
	x[2] = 1;
	x[3] = 2;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=2){
			sta[i] = x[2];
		}else if(n==3){
			sta[i] = x[3];
		}else{
			for(int w=4;w<=n;w++){
				x[w] = x[w-1]+x[w-2];
			}
			sta[i] = x[n];
		}
		i++;
	}
	for(int j=0;j<i;j++){
		cout<<sta[j]<<endl;
	}
	return 0;
}