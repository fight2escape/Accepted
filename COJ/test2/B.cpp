#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	int a[4];
	cin>>t;
	int i,j,k;
	int temp;
	int sum;
	bool flag;
	while(t--){
		for(i=0;i<4;i++){
			cin>>a[i];
		}
		flag = true;
		for(i=0;i<4;i++){
			if(a[i]){
				continue;
			}else{
				flag = false;
			}
		}
		if(flag == false){
			cout<<"No"<<endl;
			continue;
		}
		flag = true;
		for(i=3;i>0;i--){
			for(j=0;j<i;j++){
				if(a[j]>a[j+1]){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}

		if((a[0]+a[1]+a[2])>a[3]){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}

	}
	return 0;	
}
