#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[105][9999];
int main(){
	int t;
	cin>>t;
	int i,j,k;
	int n;
	int m;
	int a[205];
	int b[205];
	int temp,temp2;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n>>m;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		a[0] = b[0] = 0;
		for(i=1;i<=m;i++){
			cin>>a[i]>>b[i];
		}
		for(i=0;i<=n;i++){
			dp[0][i] = 9999;
		}
		for(i=1;i<=m;i++){
			dp[i][0] = 9999;
			for(j=1;j<=n;j++){
					temp = j;
					for(k=1;k<b[i];k++){
						temp = temp * temp;
					}
					if(b[i]==0){
							temp = a[i];
						}else{
							temp = a[i]*temp;
						}
//					temp = a[i]*temp;
					if(dp[i-1][j]<temp){
						temp = 1;
						for(k=1;k<b[i];k++){
							temp = temp * temp;
						}
						if(b[i]==0){
							temp = a[i];
						}else{
							temp = a[i]*temp;
						}
						
						dp[i][j] = (dp[i-1][j]<(dp[i-1][j-1]+temp))?dp[i-1][j]:dp[i-1][j-1]+temp;
					}else{
						temp2 = 1;
						for(k=1;k<b[i];k++){
							temp2 = temp2 * temp2;
						}
						temp2 = a[i]*temp2;
				
					}
					
				
			}
		}
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				cout<<dp[i][j]<<"   ";
			}
			cout<<endl;
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;	
}
