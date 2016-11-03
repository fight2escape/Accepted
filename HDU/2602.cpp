
//01±≥∞¸Œ Ã‚

#include <iostream>
#include <algorithm>
using namespace std;

int tb[1024][1024];
int main(){
    int t;
    cin>>t;
    int n,c;
    int val[1024],wet[1024];
    int i,j,k;

    while(t--){
        cin>>n>>c;
        val[0] = 0;
        for(i=1;i<=n;i++){
            cin>>val[i];
        }
        wet[0] = 0;
        for(i=1;i<=n;i++){
            cin>>wet[i];
        }
        for(i=0;i<=c;i++){
            tb[0][i] = 0;
        }
        for(i=1;i<=n;i++){
            for(j=0;j<=c;j++){
                if(j<wet[i]){
                    tb[i][j] = tb[i-1][j];
                }else{
                    tb[i][j] = max(tb[i-1][j],tb[i-1][j-wet[i]]+val[i]);
                }
            }
        }
        /*
          for(i=0;i<=n;i++){
            for(j=0;j<=c;j++){
                cout<<tb[i][j]<<"   ";
            }
            cout<<endl;
        }
        */
        cout<<tb[n][c]<<endl;

    }

    return 0;
}
