#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n, a, c;
int u,o,e;

void solve(int n){
    cout<<"Round 0: "<<u<<" undefeated, "<<o<< " one-loss, "<<e<<" eliminated"<<endl;
    while(1){
        if(u+o == 1){
            cout<<"There are "<<c<<" rounds.";
            return;
        }
        c++;
        if(u+o ==2){
           if(u!=0){
            u-=1; o++;
           }
           else if(u==0){
            o--; e++;
           }
        }
        else{
            int b = o>>1; o-=b; e+=b;
            b = u>>1; u-=b; o+=b;
        }
        cout<<"Round "<<c<<": "<<u<<" undefeated, "<<o<< " one-loss, "<<e<<" eliminated"<<endl;
    }
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a; u = a; o = e =c= 0;
        solve(a);
        cout<<endl;
    }
}
