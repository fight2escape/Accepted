#include<iostream>
using namespace std;
int main(){
    int n;
    int a[200][200];
    int m;
    while(cin>>n && n){
        a[199][199] = {0};
        m = 1;
        int down = 0;//列
        int left = n-1;//行
        int up = n-1;//列
        int right = 0;//行
        int start = 0;
        int endof = n-1;
        while(m <= n*n){
            if(m==n*n){
                a[start][start] = m;
                break;
            }
            for(int i=start;i<endof;i++){
                a[i][down] = m++;
            }

            if((m-1)==n*n){break;}
            for(int i=start;i<endof;i++){
                a[left][i] = m++;
            }
            if((m-1)==n*n){break;}
            for(int i=endof;i>start;i--){
                a[i][up] = m++;
            }
            if((m-1)==n*n){break;}
            for(int i=endof;i>start;i--){
                a[right][i] = m++;
            }
            if((m-1)==n*n){break;}
            start++;
            endof--;
            down++;
            left--;
            up--;
            right++;

        }
        for(int i=0;i<n;i++){
            cout<<a[i][0];
            for(int j=1;j<n;j++){
                cout<<" "<<a[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}
