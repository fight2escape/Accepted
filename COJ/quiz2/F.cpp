//Problem 1078
//705060 2 =60
//10086 2/3
/*
    初级思路：删除规则如下
    扫描一遍，删除一个数后重新扫描
    1、从左到右扫描，左边的数比右边大，删除左边
    2、如果1中没有删除数字，则继续扫描，从右往左扫描，左右相等则删除右边的，左小右大则删除右的
*/
#include<iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    string str;
    int n;
    int nb[300][2];
    int i,j,k;
    int sz;
    bool flag;
    while(t--){
        cin>>str>>n;
        sz = str.size();
        for(i=0;i<sz;i++){
            nb[i][0] = str[i] - '0';
            nb[i][1] = 1;
        }
        for(i=0;i<n;i++){
            flag = true;
            for(j=0;j<sz;j++){
                if(nb[j][1]){
                    k=1;
                    while(!nb[j+k][1]){
                        k++;
                    }
                    if(nb[j][0]>nb[j+k][0]){
                        nb[j][1] = 0;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                for(j=sz-1;j>0;j--){
                    if(nb[j][1]&&nb[j]){
                         k=1;
                         while(!nb[j-k][1]){
                            k++;
                         }
                         if(nb[j][0]>=nb[j-k][0]){
                            nb[j][1] = 0;
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }
//        for(i=0;i<sz;i++){
//            cout<<nb[i][0]<<"  "<<nb[i][1]<<endl;
//        }
        flag = true;
        for(i=0;i<sz;i++){
            if(nb[i][1]&&(nb[i][0]>0)){
                for(j=i;j<sz;j++){
                    if(nb[j][1]){
                        cout<<nb[j][0];
                        flag = false;
                    }
                }
                break;
            }
        }
        if(flag){
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
