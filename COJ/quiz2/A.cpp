#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a;
    bool flag;
    bool two;
    int res[2];
    while(t--){
        cin>>a;
        two = false;
        if(a==2){
            cout<<2<<" "<<2<<endl;
            continue;
        }
        for(int i=a;i>1;i--){
            flag = true;

            for(int j=2;j<i;j++){
                if(i%j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag&&!two){
                res[0] = i;
                //cout<<i;
                two = true;
            }else if(flag && two){
                res[1] = i;
                cout<<res[1]<<" "<<res[0]<<endl;
                //cout<<" "<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
