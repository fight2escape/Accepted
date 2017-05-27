#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int dp[800][800];
int main(){
	int t;
	cin>>t;
	string str;

	int i,j,k;
	int sz;
	int time;
    bool flag;
    string exist;
    int esz;
	while(t--){
        cin>>str;
        sz = str.size();
        exist = " ";
        exist += str[0];
        for(i=1;i<sz;i++){
            //    cout<<"existsssss"<<exist.find(str[i])<<endl;
            if(exist.find(str[i])==string::npos){
                exist+=str[i];
             //   cout<<"exist:"<<exist<<endl;
            }
        }
        //cout<<"size:"<<exist.size()-1<<endl;
        esz = exist.size()-1;
        memset(dp,0,esz*sz*sizeof(int));
        for(i=0;i<=sz;i++){
            dp[0][i] = 1;
            dp[1][i] = i;
        }
        for(i=0;i<esz;i++){
            dp[i][0] = 0;
        }
        for(i=2;i<=esz;i++){
            dp[i][i-1] = 0;
            for(k=0;k<i-1;k++){
                if(str[k]>=str[k+1]){
                   dp[i][i] = 0;
                   break;
                }else{
                    dp[i][i] = 1;
                }
            }
            for(j=i+1;j<=sz;j++){
                time = j-1;
                flag = true;
                for(k=0;k<j-1;k++){
                    if(str[j-1]<=str[k]){
                        flag = false;
                        time--;
                    }
                }
                if(flag){
                    dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][time];
                }

            }
        }
        for(i=0;i<=esz;i++){
            for(j=0;j<=sz;j++){
                cout<<dp[i][j]<<"    ";
            }
            cout<<endl;
        }
        flag = false;
        for(i=sz;i>0;i--){
            if(dp[i][sz]>0){
                if(dp[i][sz]!=1){
                    cout<<i<<endl;
                    break;
                }else if(dp[i][sz]==1 && flag){
                    cout<<i<<endl;
                    break;
                }else{
                    flag = true;
                }
            }
        }
	}
	return 0;
}
