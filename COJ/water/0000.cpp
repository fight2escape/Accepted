#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int le,wd;
    char ch;
    int i,j;
    while(n--){
        cin>>le>>wd>>ch;
        cout<<ch;
        for(i=1;i<le;i++){
            cout<<" "<<ch;
        }
        cout<<endl;
        if(wd>1){
            for(i=0;i<wd-2;i++){
                cout<<ch<<" ";
                for(j=2;j<le;j++){
                    cout<<"  ";
                }
                cout<<ch<<endl;
            }
            cout<<ch;
            for(i=1;i<le;i++){
                cout<<" "<<ch;
            }
            cout<<endl;
        }

    }


    return 0;
}
