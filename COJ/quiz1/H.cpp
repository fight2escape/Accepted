#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,m;
    int i,j,k;
    int a[105];
    int dp[105][105];
    bool flag;
    int c[105];

    while(t--){
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<=m;i++){
            dp[0][i] = 0;
            dp[1][0] = 0;
        }
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(i=2;i<=n;i++){
            dp[i][0] = 1;
            for(j=1;j<=m;j++){
                if(j==i){
                    flag = true;
                    for(k=0;k<j;k++){
                        if(a[i-1]<=a[k]){
                            flag = false;
                            break;
                        }
                    if(flag == false){
                        dp[i][j] = 0;
                    }else{
                        if(dp[i-1][j-1]==1){
                            dp[i][j] = 1;
                        }else{
                            dp[i][j] = 0;
                        }
                    }

                    }
                }else if(j<i){
                    for(k=0;k<i-1;k++){
                        if(a[i-1]>a[k]&&((dp[k+1][j-1]+dp[k+1][j])>dp[i][j])){
                            dp[i][j] = dp[k+1][j-1]+dp[k+1][j];
                        }
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                cout<<dp[i][j]<<"   ";
            }
            cout<<endl;
        }


        cout<<dp[n][m]<<endl;
    }

	return 0;
}
