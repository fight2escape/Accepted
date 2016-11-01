#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a;
    int w[6];

    int jin;
    while(t--){
        w[6] = {0};
       int k=0;
       cin>>a;
       while(a>0){
            //cout<<a<<endl;
        w[k] = a%10;
        a /= 10;
        //cout<<w[k]<<"----------"<<a<<"--------"<<k<<endl;
        k++;
       }

       jin = 0;
        int sum[7] = {0};
       for(int i=k-1,j=0;i>=0;i--,j++){
            //cout<<w[i]<<"/"<<w[j]<<"-------"<<endl;
            if((w[i]+w[j]+jin)>=10){
                sum[i+1] = (w[i]+w[j]+jin)%10;
                jin=1;
                if(i==0){
                    sum[0] = 1;
                }
            }else{
                sum[i+1] = (w[i]+w[j])+jin;
                jin = 0;
            }
        }
        bool fl = false;
        if(sum[0]==1){
            cout<<sum[0];
            fl = true;
        }
        for(int i=1;i<=k;i++){
            cout<<sum[i];
        }
         if(sum[0]==1){
            //cout<<endl<<sum[0]<<"/";
            k++;
        }
        cout<<" "<<k<<endl;
    }
    return 0;
}
