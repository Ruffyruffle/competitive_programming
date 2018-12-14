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
#define pii pair<int,int>
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,m;
vector<int> par, rk;
vector<pair<int, pii> >a;


void create(){
    for(int i = 0 ; i < n ; i ++){
        par[i] = i;
        rk[i] = 0;
    }
}

int fnd(int a){
    if(par[a] == a) return a;
    return par[a] = fnd(par[a]);
}

void onion(int a, int b){
    a = fnd(a); b = fnd(b);
    if(rk[a] < rk[b]){
        swap(a,b);
    }
    par[b] = a;
    if(rk[a] == rk[b])
        rk[a]++;
}

int main(){
    cin>>n>>m;
    rk.resize(n);
    par.resize(n);
    create();
    for(int i = 0,x,y,v; i < n; i++){
        cin>>x>>y>>v;
        a.pb({v,{x,y}});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());


    int ans = 0;
    for(pair<int,pii> i : a){
        if(fnd(i.second.second) != fnd(i.second.first)){
            ans+= i.first;
            onion(i.second.first, i.second.second);
        }
    }
    cout<<ans;
}
