/*
思路如下：
设置一个数组s，数组下标正好是每个人的编号，初始化为零，当有同乡关系时，
对这两个数进行判断后分组，最后将组数，以及没有分到组的人数相加既得，当然还要减一，因为为了方便s[0]=0；
判断流程如下：
设置一个变量t=1；
如果a+b==0,说明都还没分到组，赋予 t 值，然后t++；
否则看下 a 和 b 哪个为零，将不为零的值赋给它，归为一组，然后继续循环
*/
#include <iostream>
using namespace std;

int s[50005];
int main(){
	int n,m;
	int i,j,k;
	int t;
	int t1,t2;
	int time;
	while(cin>>n>>m && n+m){
		s[0] = 0;
		for(i=1;i<=n;i++){
			s[i] = 0;
		}
		t=1;
		for(i=0;i<m;i++){
			cin>>t1>>t2;
			if((s[t1]+s[t2])==0){
				s[t1] = s[t2] = t;
				t++;
			}else{
				if(s[t1]!=0){
					s[t2] = s[t1];
				}else{
					s[t1] = s[t2];
				}
			}
		}
		time=0;
		for(i=1;i<=n;i++){
			if(s[i]==0){
				time++;
			}
		}
		cout<<time+t-1<<endl;
	}

	return 0;
}
