#include<iostream>
#include<string>
using namespace std;
int main(){
    string fr;
    string str;
    for(int i=0;i<3;i++){
        cin>>fr>>str;
        int len = str.size();
        int lenf = fr.size();
        bool flag = false;
        int f=0;
        for(int j=0;j<len;j++){
            if(str[j] == fr[f]){
                f++;
                if(f==lenf){
                    cout<<"OK"<<endl;
                    break;
                }
            }
        }
        if(f<lenf){
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
