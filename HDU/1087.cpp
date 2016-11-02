#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a[1024];
    int dp[1024];
    int i,j;
    int ans;

    while(cin>>n && n){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        dp[0] = a[0];
        ans = dp[0];
        for(i=1;i<n;i++){
            dp[i] = a[i];
            for(j=0;j<i;j++){
                if(a[i]>a[j]&&dp[j]+a[i]>dp[i]){
                    dp[i] = dp[j]+a[i];
                }
            }
            if(dp[i]>ans){
                ans = dp[i];
            }
        }
        cout<<ans;
    }

    return 0;
}
