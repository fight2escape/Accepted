#include <iostream>
using namespace std;
int main(){
	int app[10] = {0};
	int base = 0;
	#define ADD 30;
	while(cin>>app[0]&&app[0]){
		for(int i=1;i<10;i++){
			cin>>app[i];
		}
		cin>>base;

		int sum = 0;
		int tall = base+ADD;
		for(int j=0;j<10;j++){
			if(app[j]<=tall){
				sum++;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}
