#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string res[100];
	int k = 0;
	double sum,avg;
	int team[9];
	while(n--){
		for(int i=0;i<9;i++){
			cin>>team[i];
		}
		sum=0;
		for(int j=1;j<9;j++){
			sum += team[j];
		}
		avg = sum/8.0;
		if(avg <= team[0]){
			res[k] ="Relaxed";
		}else{
			res[k] = "Stressed";
		}
		k++;
	}
	for(int m=0;m<k;m++){
		cout<<res[m]<<endl;
	}
	return 0;
}