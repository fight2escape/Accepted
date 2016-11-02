#include <iostream>
using namespace std;

int getNum(int h){
    int sum=0;
    for(int i=1;i<=h;i++){
        sum += i;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    int h;
    int num;
    int i,j,k;
    int s[6000];
    int sum[6000];
    int mx;
    while(t--){
        cin>>h;
        num = getNum(h);
        for(i=0;i<num;i++){
            cin>>s[i];
        }
        sum[0] = s[0];
        for(i=2;i<=h;i++){
            sum[getNum(i-1)] = s[getNum(i-1)]+sum[getNum(i-2)];
            sum[getNum(i)-1] = s[getNum(i)-1]+sum[getNum(i-1)-1];
            for(j=getNum(i-1)+1;j<getNum(i)-1;j++){
                sum[j] = s[j]+((sum[j-i]>=sum[j-i+1])?sum[j-i]:sum[j-i+1]);
            }
        }
        mx = sum[getNum(h-1)];
        for(i=getNum(h-1)+1;i<getNum(h);i++){
            if(sum[i]>mx){
                mx = sum[i];
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
