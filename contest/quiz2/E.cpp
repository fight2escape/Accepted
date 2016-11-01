//Problem 1060 地铁隧道设置无线基站
//思路：先对输入的各段长度从小到大排序，然后选择符合一定范围的最远地点搭建，
//再以此为起点，加上两倍的电波半径作为终点，在此范围内再找符合条件的点，循环
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n,r;
    int site[200];
    int i,j;
    int temp;
    int start,endof;
    int cursite;
    int time;
    int k;
    int length = 100000;
    while(t--){
       cin>>n>>r;
       for(i=0;i<n;i++){
        cin>>site[i];
       }
       //从小到大排序
       for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(site[j]>site[j+1]){
                temp = site[j];
                site[j] = site[j+1];
                site[j+1] = temp;
            }
        }
       }
       //初始化参数
       cursite = -r;
       time = 0;
       k = 0;
       start = cursite;
       endof = start+2*r;
       //循环计算出所需次数
       while(0<=(cursite+r)&&(cursite+r)<length){
          cursite = -1;
          //记录下可以建站的最远处
           for(i=k;i<n;i++)  {
            if(start<site[i]&&site[i]<=endof){
                cursite = site[i];
                k = i;//省得重复计算前面的值
            }
           }
           //如果不等于-1，说明有可以建站的地方
           if(cursite!=-1){
            time++;
            start = cursite;
            endof = start+2*r;
           }else{
            break;//条件不足，退出循环
           }
       }
       cout<<time<<endl;
    }
    return 0;
}
