#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i,j,k;
    int a[1024];
    int mx,temp;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    mx = 0;
    for(i=0;i<n-1;i++){
        temp = a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i];
        mx = temp>mx?temp:mx;
    }
    cout<<mx<<endl;
    return 0;
}
