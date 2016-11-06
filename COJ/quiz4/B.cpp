#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	string s;
	int time[6];
	int sz;
	int i,j,k;
	string res;
	int re[3000];
	int r=0;
	while(getline(cin,s) && s[0]!='#'){
		getline(cin,str);
		for(i=0;i<s.size();i++){
			time[i] = 0;
			for(j=0;j<str.size();j++){
				if(s[i]==str[j]){
					time[i]++;
				}
			}
		}
		for(i=0;i<s.size();i++){
			//cout<<s[i]<<"\t"<<time[i]<<endl;
			res+=s[i];
			re[r] = time[i];
			r++;
		}
	}
	for(i=0;i<r;i++){
		if(i>0){
			cout<<endl;
		}
		cout<<res[i]<<" "<<re[i];
	}
	return 0;
}
