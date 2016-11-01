#include <iostream>
using namespace std;
int main(){
	char num[99][2][4];
	int i=-1;
	do{
		i++;
		cin>>num[i][0]>>num[i][1];
	}while(!(num[i][0][0]=='0' && num[i][1][0]=='0'));
	
	for(int j=0;j<i;j++){
		bool flag = false;
		int time = 0;
		for(int k=2;k>=0;k--){
			int a = num[j][0][k]-'0';
			int b= num[j][1][k]-'0';
			int sum =  a + b;
			if(flag){
				sum += 1;
			}
			if(sum>9){
				time++;
				flag = true;
			}else{
				flag = false;
			}
		}
		cout<<time<<endl;
	}
	
	return 0;
}