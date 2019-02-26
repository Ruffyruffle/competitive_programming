#include<bits/stdc++.h>
int n;
#define MAXN 1
using namespace std;

int main(){
    int x,y;
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x;
        if(1000 > x){
            cout<<"Newbie\n";
        }
        else if(1200 > x){
            cout<<"Amateur\n";
        }
        else if(1500 > x){
            cout<<"Expert\n";
        }
        else if(1800 > x){
            cout<<"Candidate Master\n";
        }
        else if(2200 > x){
            cout<<"Master\n";
        }
        else if(3000 > x){
            cout<<"Grandmaster\n";
        }else if(4000 > x){
            cout<<"Target\n";
        }
        else cout<<"Rainbow Master\n";
    }

}
