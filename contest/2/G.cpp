#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    int len;
    bool flag;
    while(n--){
        cin>>str;
        len = str.size();
        flag = true;
        for(int i=0;i<len/2;i++){
            if(str[i] != str[len-1-i]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
