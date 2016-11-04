#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[105][9999];
int main(){
	int t;
	cin>>t;
	int i,j,k;
	int tmx;
	int n;
	int c[105];
	int v[105];
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>tmx>>n;
		c[0] = v[0] = 0;
		for(i=1;i<=n;i++){
			cin>>c[i]>>v[i];
		}
		for(i=0;i<=tmx;i++){
			dp[0][i] = 0;
		}
		for(i=1;i<=n;i++){
			dp[i][0] = 0;
			for(j=1;j<=tmx;j++){
				if(j<c[i]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
				}
			}
		}
//		for(i=0;i<=n;i++){
//			for(j=0;j<=tmx;j++){
//				cout<<dp[i][j]<<"   ";
//			}
//			cout<<endl;
//		}
		cout<<dp[n][tmx]<<endl;
	}
	return 0;	
}
