#include<iostream>
using namespace std;
int main(){
    int t,i=0;
    cin>>t;
    char str[20][3];
    while(t--){
        cin>>str[i][0]>>str[i][1]>>str[i][2];
        if(str[i][1] == '+'){
            cout<<str[i][0]+str[i][2]-'0'-'0'<<endl;
        }else{
            cout<<str[i][0]-str[i][2]<<endl;
        }
    }
    return 0;
}
