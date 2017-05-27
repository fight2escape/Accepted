#include <iostream>
using namespace std;
//思想，以第一个输入值作为最大值，加上下一个输入值后，如果值小于零，就舍弃所有前面的输入值，从下一个新的作为起点开始。
//如果加上下一个输入值后，超过了目前的最大值，则更新最大值，以及最大值终点
//如果加上下一个输入值后，没有小于零也没有大于最大值，则先保留，继续读取
int main(){
	int t;
	int num,arr;
	int res[20][3] = {0};
	cin>>t;
	int i=0;
	int max,temp;
	int mm,nn;
	int j;
	while(t--){
		cin>>num;
		max = 0;
		temp = 0;
		for(j=1;j<=num;j++){
			cin>>arr;
			if(j==1){
				max = arr; 
				mm = 1;
				nn = 1;
			}
			if((temp+arr)<0){
				temp = 0;
				mm = j+1;
				
			}else if(temp+arr > max){
				temp += arr;
				max = temp;
				nn = j;
			}else{
				temp += arr;
			}
		}				
		res[i][0] = max;
		res[i][1] = mm;
		res[i][2] = nn;
		i++;		
	}	
	for(int k=0;k<i;k++){
		cout<<"Case "<<k+1<<":"<<endl;
		cout<<res[k][0]<<" "<<res[k][1]<<" "<<res[k][2]<<endl;
		if(k+1<i){cout<<endl;}
	}	
	return 0;
}