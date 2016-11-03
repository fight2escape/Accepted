
//免费馅饼
//思路：想象成棋盘上机器人向右下角收集金币。
//类似01背包，构造表格，X轴为0到10的11个数，y轴为时间轴。
//哪个位置有馅饼，在该位置加一，可累计
//在原表的基础上，算出每个位置可能累计的最大值
//当前格的值等于，上一行，同一个位置本身以及左右两个值，三个数之间的最大值，再加上本格的数量

//特别注意，一开始是在最中间，给你时间也够不到的馅饼要舍弃，不能算，特别注意

#include <iostream>
#include <algorithm>//一些常用的计算函数，比如max();
#include <stdio.h>//为了用scanf()输出，提高输入效率，防止超时
#include <string.h>//为了使用memset();

using namespace std;

int tb[102400][12];
int n;
int x,t;
int i,j,k;
int tmx;
int ans;

int main(){

    while(cin>>n && n){
        memset(tb,0,sizeof(tb));//将数组清零，否则会累计起来导致错误
        tmx = 0;
        for(i=0;i<n;i++){
            //cin>>x>>t;
            scanf("%d",&x);
            scanf("%d",&t);
            if(t>tmx){
                tmx = t;//记录下时间终点
            }
            if(abs(x-5)<=t){//这里特别注意，需要筛选出有效的馅饼，也就是给了时间确实能够到的才能算进表内
                tb[t][x] += 1;
            }
        }
        for(i=0;i<11;i++){
            tb[0][i] = 0;//表格首行初始化
        }
        for(i=1;i<=tmx;i++){
            //因为两边会越界，所以单独特殊计算
            tb[i][0] = max(tb[i-1][0],tb[i-1][1])+tb[i][0];
            tb[i][10] = max(tb[i-1][9],tb[i-1][10])+tb[i][10];
            for(j=1;j<10;j++){
                //与01背包类似，只是比较的是三个数
                tb[i][j] = max(tb[i-1][j-1],max(tb[i-1][j],tb[i-1][j+1]))+tb[i][j];
            }
        }
        /*
        for(i=0;i<=tmx;i++){
            for(j=0;j<11;j++){
                cout<<tb[i][j]<<"   ";
            }
            cout<<endl;
        }
        */
        ans = 0;
        for(i=0;i<11;i++){
            if(tb[tmx][i]>ans){
                ans = tb[tmx][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
