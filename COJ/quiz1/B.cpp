#include <iostream>
using namespace std;
int main(){
	int tree[10001];
	int num,group;
	int cut[101][2];
	int sum;
	while(cin>>num && num){
		cin>>group;
		for(int i=0;i<group;i++){
			cin>>cut[i][0]>>cut[i][1];
		}
		for(int j=0;j<=num;j++){
			tree[j] = 1;
		}
		for(int q=0;q<group;q++){
			for(int k=cut[q][0];k<=cut[q][1];k++){
				tree[k] = 0;
			}
		}
		sum = 0;
		for(int p=0;p<=num;p++){
			if(tree[p]==1){
				sum++;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}