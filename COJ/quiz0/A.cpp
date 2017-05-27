#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,i=0;
	cin>>n;
	string str[99][99];
	int time[99][99] = {0};
	int out_arr[99][99] = {0};
	int out_time[99] = {0};
	while(n != 0){
		for(int j=0;j<n;j++){
			cin>>str[i][j];
		}
		for(int k=0;k<n-1;k++){
			for(int m=k+1;m<n;m++){
				if(str[i][k] == str[i][m]){
					time[i][k]++;
				}
			}
		}
		int max = time[i][0];
		for(int p=1;p<n;p++){
			if(max<time[i][p]){
				max = time[i][p];
			}
		}

		int equal_i = 0;
		for(int q=0;q<n;q++){
			if(max==time[i][q]){
				out_arr[i][equal_i] = q;
				equal_i++;
			}
		}
		out_time[i] = equal_i;
		for(int r=equal_i-1;r>=0;r--){
			for(int s=0;s<r;s++){
				if(str[i][s]>str[i][s+1]){
					string temp = str[i][s];
					str[i][s] = str[i][s+1];
					str[i][s+1] = temp;
				}
			}
		}
		i++;
		cin>>n;
	}
	for(int ii=0;ii<i;ii++){
		for(int kk=0;kk<out_time[ii];kk++){
			cout<<str[ii][out_arr[ii][kk]]<<endl;
		}
		
	}
	return 0;
}