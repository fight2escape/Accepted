#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin>>t;
	string str;
	int c[1024];
	int ans;
	int i,j,k;
	int sz;
	while(t--){
        cin>>str;
        sz = str.size();
        c[0] = 1;
        ans = -9999;
        for(i=1;i<sz;i++){
            c[i] = 1;
            for(j=0;j<i;j++){
                if(str[i]<str[j]&&(c[j]+1>c[i])){
                    c[i] = c[j]+1;
                }
            }
            if(ans <c[i]){
                ans = c[i];
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
