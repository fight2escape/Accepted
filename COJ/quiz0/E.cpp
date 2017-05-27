#include <iostream>
#include <string>
using namespace std;
int getRank(string);
int main(){
	int t,n,nn[100]={0};
	string s[10][100];
	int i=0,j=0,k=0;
	string temp;
	cin>>t;
	while(t--){
		cin>>n;
		nn[i] = n;
		for(j=0;j<n;j++){
			cin>>s[i][j];
		}
		for(j=n-1;j>0;j--){
			for(k=0;k<j;k++){
				if(getRank(s[i][k])>getRank(s[i][k+1])){
					temp = s[i][k];
					s[i][k] = s[i][k+1];
					s[i][k+1] = temp;
				}
			}
		}
		i++;
	}
	for(int p=0;p<i;p++){
		for(int q=0;q<nn[p];q++){
				if(q!=0){cout<<" ";}
				cout<<s[p][q];		
		}
		cout<<endl;
	}
	return 0;
}

//获取扑克排序大小
int getRank(string ch){
	if(ch == "3"){return 3;
	}else if(ch == "4"){return 4;
	}else if(ch == "5"){return 5;
	}else if(ch == "6"){return 6;
	}else if(ch == "7"){return 7;
	}else if(ch == "8"){return 8;
	}else if(ch == "9"){return 9;
	}else if(ch == "10"){return 10;
	}else if(ch == "J"){return 11;
	}else if(ch == "Q"){return 12;
	}else if(ch == "K"){return 13;
	}else if(ch == "A"){return 14;
	}else if(ch == "2"){return 15;
	}else{return 0;}
}
