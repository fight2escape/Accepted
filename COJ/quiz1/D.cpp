#include <iostream>
using namespace std;
//˼�룬�Ե�һ������ֵ��Ϊ���ֵ��������һ������ֵ�����ֵС���㣬����������ǰ�������ֵ������һ���µ���Ϊ��㿪ʼ��
//���������һ������ֵ�󣬳�����Ŀǰ�����ֵ����������ֵ���Լ����ֵ�յ�
//���������һ������ֵ��û��С����Ҳû�д������ֵ�����ȱ�����������ȡ
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