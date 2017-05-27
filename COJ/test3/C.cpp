#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a[20];
    int temp;
    for(int i=0;i<2*t;i++){
        cin>>a[i];
    }
    for(int k=2*t-1;k>0;k--){
       for(int j=0;j<k;j++){
        if(a[j]>a[j+1]){
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
       }
    }
    float mid;
    mid = ((float)(a[t-1]+a[t]))/2;
    cout<<mid<<endl;
    return 0;
}
