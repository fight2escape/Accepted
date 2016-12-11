#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[101];
    int i,j,k;
    a[0] = -1;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    string s[21];
    s[0] = "#";
    int site;
    int sz;
    for(i=1;i<=a[1];i++){
        s[1] += "1";
        if(i!=1){cout<<" ";}
        cout<<i;
    }
    cout<<endl;

    site = 0;
    int temp;
    for(i=2;i<=n;i++){
        temp = a[i];
        for(j=1;j<=20;j++){
            if(a[i]<=5-s[j].size()){
                site = (j-1)*5+s[j].size();
                for(k=0;k<a[i];k++){
                    if(k!=0){cout<<" ";}
                    cout<<++site;
                    s[j] += "1";
                    temp--;

                }
                cout<<endl;
                break;
            }
        }
        if(temp==a[i]){
            for(j=1;j<=20;j++){
                if(5-s[j].size()>0){
                    site = (j-1)*5+s[j].size();
                    sz = s[j].size();
                    //s[j].size()是会变的，应该先记录下来，再放到for中做判断条件
                    for(k=0;k<5-sz;k++){
                        if(temp!=a[i]){cout<<" ";}
                        cout<<++site;
                        s[j]+="1";
                        temp--;
                    }
                    if(temp==0){
                        cout<<endl;
                        break;
                    }
                }
            }
        }

    }

    return 0;
}
