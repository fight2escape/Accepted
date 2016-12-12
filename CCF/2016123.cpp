#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string act;
    struct killer
    {
        //int hero;
        //int num;
        int attack;
        int health;
    };
    int num,attack,health;
    int attacker,defender,temper;
    killer first[8];
    killer second[8];
    //first[0].hero = 1;
    //second[0].hero = 2;
    first[0].attack = second[0].attack = 0;
    first[0].health = second[0].health = 30;
    int sp1=1,sp2=1;
    int i,j,k;
    int flag;
    int res;

    flag = true;//真为先手，假为后手
    for(i=0;i<n;i++){
        cin>>act;
        if("summon" == act){
            cin>>num>>attack>>health;
            if(!(first[0].health>0&&second[0].health>0)){
                continue;
            }
            if(flag){
                if(num<sp1){
                    for(j=sp1;j>num;j--){
                        first[j] = first[j-1];
                    }
                }
                first[num].attack = attack;
                first[num].health = health;
                sp1++;
                //cout<<"summon first:"<<num<<"/"<<sp1<<endl;
            }else{
                if(num<sp2){
                    for(j=sp2;j>num;j--){
                        second[j] = second[j-1];
                    }
                }
                second[num].attack = attack;
                second[num].health = health;
                sp2++;
                //cout<<"summon second:"<<num<<"/"<<sp2<<endl;
            }
        }else if("attack" == act){
            cin>>attacker>>defender;
            if(!(first[0].health>0&&second[0].health>0)){
                continue;
            }
            if(!flag){
                temper = attacker;
                attacker = defender;
                defender = temper;
            }
            if((attacker>0&&defender>0)&&(sp1>1 && sp2>1) || (attacker==0||defender==0)){

                second[defender].health -= first[attacker].attack;
                first[attacker].health -= second[defender].attack;
                if(first[attacker].health<=0){
                    //cout<<"first dead:"<<attacker<<":"<<first[attacker].health<<endl;
                    if(attacker!=0){
                        for(j=attacker;j<sp1;j++){
                            first[j] = first[j+1];
                        }
                        sp1--;
                    }
                }
                if(second[defender].health<=0){
                    //cout<<"second dead:"<<defender<<":"<<second[defender].health<<endl;
                    if(defender!=0){
                        for(j=defender;j<sp2;j++){
                            second[j] = second[j+1];
                        }
                        sp2--;
                    }
                }
            }

        }else{
            flag = flag?false:true;
            //cout<<"flag change:"<<flag<<endl;
        }
    }

    if(first[0].health<=0){
        res = -1;
    }else if(second[0].health<=0){
        res = 1;
    }else{
        res = 0;
    }
    cout<<res<<endl;
    cout<<first[0].health<<endl;
    cout<<sp1-1<<" ";
    for(i=1;i<sp1;i++){
        if(i!=1){cout<<" ";}
        cout<<first[i].health;
    }
    cout<<endl;
    cout<<second[0].health<<endl;
    cout<<sp2-1<<" ";
    for(i=1;i<sp2;i++){
        if(i!=1){cout<<" ";}
        cout<<second[i].health;
    }
    cout<<endl;

    return 0;
}
