#include<iostream>
using namespace std;
int main(){
    int t,i=0;
    cin>>t;
    char g = ' ';
    int w,h;
    while(t--){
        cin>>w>>h>>g;
        //
        cout<<g;
        for(int i=1;i<w;i++){
            cout<<" "<<g;
        }
        cout<<endl;
        if(h>1){
            if(h>2){
                for(int j=0;j<h-2;j++){
                    cout<<g;
                    for(int i=1;i<w-1;i++){
                        cout<<" "<<" ";
                    }
                    cout<<" "<<g<<endl;
                }
            }
            cout<<g;
            for(int i=1;i<w;i++){
                cout<<" "<<g;
            }
            cout<<endl;
        }
    }
    return 0;
}
