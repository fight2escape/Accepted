//Problem 1060 ��������������߻�վ
//˼·���ȶ�����ĸ��γ��ȴ�С��������Ȼ��ѡ�����һ����Χ����Զ�ص���
//���Դ�Ϊ��㣬���������ĵ粨�뾶��Ϊ�յ㣬�ڴ˷�Χ�����ҷ��������ĵ㣬ѭ��
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
       //��С��������
       for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(site[j]>site[j+1]){
                temp = site[j];
                site[j] = site[j+1];
                site[j+1] = temp;
            }
        }
       }
       //��ʼ������
       cursite = -r;
       time = 0;
       k = 0;
       start = cursite;
       endof = start+2*r;
       //ѭ��������������
       while(0<=(cursite+r)&&(cursite+r)<length){
          cursite = -1;
          //��¼�¿��Խ�վ����Զ��
           for(i=k;i<n;i++)  {
            if(start<site[i]&&site[i]<=endof){
                cursite = site[i];
                k = i;//ʡ���ظ�����ǰ���ֵ
            }
           }
           //���������-1��˵���п��Խ�վ�ĵط�
           if(cursite!=-1){
            time++;
            start = cursite;
            endof = start+2*r;
           }else{
            break;//�������㣬�˳�ѭ��
           }
       }
       cout<<time<<endl;
    }
    return 0;
}
