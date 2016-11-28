#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int sk;
    int k;
    int i,j;
    while(cin>>s && s[0]!='0'){

            sk = 0;
            for(i=0;i<s.size();i++){
                sk += s[i]-'0';
            }
            sk = sk%9;
        if(sk==0){
            cout<<9<<endl;
        }else{
            cout<<sk<<endl;
        }


    }
    return 0;
}
