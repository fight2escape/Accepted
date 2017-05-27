#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,i=0;
    cin>>t;
    int a;
    bool flag;
    while(t--){
       cin>>a;
       for(int i=a;i>1;i--){
            flag = true;
            for(int j=2;j<sqrt(i);j++){
                if(i%j==0){
                    flag =false;
                    break;
                }
            }
            if(flag){
                cout<<i<<endl;
                break;
            }
       }
    }
    return 0;
}
