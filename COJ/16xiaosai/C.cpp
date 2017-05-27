#include <iostream>
#include <string>

using namespace std;

string subone(string str,int i){
	string str2;
	if(str[i]>'0'){
		str[i] = str[i]-1;
	}else{
		str = subone(str,i-1);
		str[i] = '9';
	}
	return str;
}
string getnext(string str){
	string temp,temp2;
	temp2 = subone(str,str.size()-1);
	for(int i=0;i<temp2.size();i++){
		if(temp2[i]!='0'){
			for(int j=i;j<temp2.size();j++){
				temp += temp2[j];
			}
			break;
		}
	}
	return temp;
}
string getmul(string str,string str2){
	string mul;
	int temp,temp2;
	int jin=0;
	int tjin=0;
	int k;
	for(int i=str2.size()-1;i>=0;i--){
		k=str2.size()-i-1;
		for(int j=str.size()-1;j>=0;j--){
			k+=str.size()-j-1;
			temp = (str2[i]-'0')*(str[j]-'0')+jin;
			jin = (temp+mul[k])/10;
			temp2 = (temp+tjin)%10;
			mul[k] = temp2;
		}
		mul[k+1] = jin;
	}
	for(int i=mul.size()-1;i>=0;i--){
		cout<<mul[i];
	}
	return mul;
	
}
int main(){
	string str;
	string temp,temp2;
	int i,j,k;

	
	while(cin>>str && str[0]!='0'){
		temp = getnext(str);
		temp2 = str;
		while(temp!=""){
			//cout<<temp<<endl;
			getmul(temp,temp2);
			temp = getnext(temp);
		}
		
		
	
	}
	
	return 0;
}
