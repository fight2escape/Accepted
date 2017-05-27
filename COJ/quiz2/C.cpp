#include<iostream>
using namespace std;

char* speak(int s){
    switch(s){
        case 0: return "ling";break;
        case 1: return "yi";break;
        case 2: return "er";break;
        case 3: return "san";break;
        case 4: return "si";break;
        case 5: return "wu";break;
        case 6: return "liu";break;
        case 7: return "qi";break;
        case 8: return "ba";break;
        case 9: return "jiu";break;
        default:return "false";
    }
}

int main(){
    int t,i=0;
    cin>>t;
    int num;
    while(t--){
      cin>>num;
      int g,s,b;
      b = num/100;
      s = num%100/10;
      g = num%10;
      cout<<speak(b)<<" bai";
      if(s>0){
          cout<<" "<<speak(s)<<" shi";
          if(g>0){
            cout<<" "<<speak(g)<<endl;
          }else{
              cout<<endl;
          }
      }else{
        if(g>0){
            cout<<" ling "<<speak(g)<<endl;
        }else{
            cout<<endl;
        }
      }


    }
    return 0;
}
