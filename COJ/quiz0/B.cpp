#include<iostream>
using namespace std;
int main(){
	int n;
	int num[50][100] = {0};
	int m = 0;
	int sum[50] = {0};
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>num[m][i];
		}
		sum[m] = 6*num[m][0]+5;
		for(int j=1;j<n;j++){		
			if(num[m][j]>num[m][j-1]){
				sum[m] += 6*(num[m][j]-num[m][j-1])+5;
			}
			if(num[m][j]<num[m][j-1]){
				sum[m] += 4*(num[m][j-1]-num[m][j])+5;
			}
		}

		m++;
		cin>>n;
	}
	for(int k=0;k<m;k++){
		cout<<sum[k]<<endl;
	}
	return 0;
}