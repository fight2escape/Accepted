#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    string a;
    int w[100];
    int temp;
    int time;

    while(t--){
        cin>>a;
        int k=0;
        time = 0;
        for(int i=0;i<a.size();i++){
            w[i] = a[i]-'0';
        }
        k=a.size();
        for(int i=k-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(w[j]>w[j+1]){
                    temp = w[j];
                    w[j] = w[j+1];
                    w[j+1] = temp;
                }
            }
        }
        bool flag = true;
        for(int m=0;m<k;m++){
            if(w[m]==0&&flag){
                time++;
                continue;
            }else{
                cout<<w[m];
            }
        }
        if(time){
                for(int q=0;q<time;q++){
                    cout<<0;
                }
                time = 0;
                flag = false;
            }
        cout<<endl;

    }
    return 0;
}
