#include <iostream>
using namespace std;

int s[50005];
int main(){
	int n,m;
	int i,j,k;
	int t;
	int t1,t2;
	int time;
	while(cin>>n>>m && n+m){
		s[0] = 0;
		for(i=1;i<=n;i++){
			s[i] = 0;
		}
		t=1;
		for(i=0;i<m;i++){
			cin>>t1>>t2;
			if((s[t1]+s[t2])==0){
				s[t1] = s[t2] = t;
				t++;
			}else{
				if(s[t1]!=0){
					s[t2] = s[t1];
				}else{
					s[t1] = s[t2];
				}
			}
		}
		time=0;
		for(i=1;i<=n;i++){
			//cout<<s[i]<<"   ";
			if(s[i]==0){
				time++;
			}
		}
		cout<<time+t-1<<endl;
	}
	
	return 0;
}
