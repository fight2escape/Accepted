#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int a[1024];
	int dp[1024];
	int i,j,k;
	int ans;
	while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        dp[0] = 1;
        ans = -99999;
        for(i=1;i<n;i++){
            dp[i] = 1;
            for(j=0;j<i;j++){
                //这里不要严格递增，否则错误，需要>=
                if(a[i]>=a[j]&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            if(ans < dp[i]){
                ans = dp[i];
            }
        }
        cout<<n-ans<<endl;
	}
	return 0;
}



