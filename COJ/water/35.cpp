#include <iostream>
using namespace std;
int main(){
    int n,m; //m��n��
    int squ[20][20]={0};//����ľ���
    int sum[40] = {0}; //��͵�����
    while(cin>>n>>m && n+m){
        //�������
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>squ[i][j];
            }
        }
        //��ȡ��һ������б�еĺ�
        int s=0;//���������±�
        for(int i=m-1;i>=0;i--){//�ӵ�һ����ײ���Ԫ�ؿ�ʼ�㣬���������㵽���Ԫ������б��
            sum[s] = 0;//��ʼ����б�е�ֵΪ0����ֹbug
            for(int j=i,k=0;j<m;j++,k++){//jΪ�У�kΪ�У�j++��k++��ʾȡб���У����½ǵ���һ��Ԫ�أ�ֱ��û��
                sum[s] += squ[j][k];
            }
            s++;
        }
        //��ȡ��һ������б�еĺͣ�ȥ�����ظ��ĵ�һ��Ԫ��
        for(int i=1;i<n;i++){//ͬ��
            sum[s] = 0;
            for(int k=0,j=i;j<n;k++,j++){
                sum[s] += squ[k][j];
            }
            s++;
        }
        //������
        for(int i=0;i<(m+n-1);i++){
            cout<<sum[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
