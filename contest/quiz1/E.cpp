#include<iostream>
using namespace std;
int main(){
   int n;
   int a[100];
   int sum;
   int ave;
   int temp;
   while(cin>>n && n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(a[j]>a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        if(n%2 != 0){
            ave = a[(n-1)/2];
        }else{
            ave = a[n/2-1];
        }
        cout<<ave<<endl;
   }
    return 0;
}
