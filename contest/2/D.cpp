#include<iostream>
using namespace std;
int main(){
   int a[3];
   int sum;
   int ave;
   int temp;
   while(cin>>a[0]>>a[1]>>a[2] && a[0]+a[1]+a[2]){
        for(int i=2;i>0;i--){
            for(int j=0;j<i;j++){
                if(a[j]>a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        cout<<a[2]-a[0]<<endl;

   }


    return 0;
}
