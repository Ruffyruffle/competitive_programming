#include<iostream>
using namespace std;
#define MAXN 10000
#define s second
#define f first
#define endl '\n'
typedef pair<int,int> pii;
int n,m,k,ans;

bool h=0,v=0;

int main(){
    string s;
    getline(cin,s);
    for(char i : s){
        if(i=='H'){
            h=!h;
        }
        if(i == 'V'){
            v=!v;
        }
    }
    if(h&&v){
        cout<<4<< " "<<3<<endl;
        cout<<2<<" "<<1;
    }
    else if(h){
        cout<<3<<" "<<4<<endl;
        cout<<1<<" "<<2;
    }
    else if(v){
        cout<<2<<" "<<1<<" "<<endl<<4<<" "<<3;
    }
    else{
        cout<<1<<" "<<2<<endl<<3<<" "<<4;
    }
    cout<<endl;
    return 0;
}
