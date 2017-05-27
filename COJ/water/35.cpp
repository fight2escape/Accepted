#include <iostream>
using namespace std;
int main(){
    int n,m; //m行n列
    int squ[20][20]={0};//输入的矩阵
    int sum[40] = {0}; //存和的数组
    while(cin>>n>>m && n+m){
        //输入矩阵
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>squ[i][j];
            }
        }
        //获取第一列所在斜行的和
        int s=0;//存和数组的下标
        for(int i=m-1;i>=0;i--){//从第一列最底部的元素开始算，从下往上算到最顶部元素所在斜行
            sum[s] = 0;//初始化此斜行的值为0，防止bug
            for(int j=i,k=0;j<m;j++,k++){//j为行，k为列，j++和k++表示取斜行中，右下角的下一个元素，直到没有
                sum[s] += squ[j][k];
            }
            s++;
        }
        //获取第一行所在斜行的和，去掉了重复的第一个元素
        for(int i=1;i<n;i++){//同上
            sum[s] = 0;
            for(int k=0,j=i;j<n;k++,j++){
                sum[s] += squ[k][j];
            }
            s++;
        }
        //输出结果
        for(int i=0;i<(m+n-1);i++){
            cout<<sum[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
