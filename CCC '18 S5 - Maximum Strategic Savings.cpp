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
int n,m,p,q;
vector<int> par, rk;
vector<pair<int, pii> >a;
vector<pair<int, pii> >b;
int old = 0, r = 0;


void create(int i){

        par[i] = i;
        rk[i] = 0;

}

int fnd(int a){
    if(par[a] == a) return a;
    return par[a] = fnd(par[a]);
}

void onion(int a, int b){
    a = fnd(a); b = fnd(b);
    if(a==b) return;
    if(rk[a] < rk[b]){
        swap(a,b);
    }
    par[b] = a;
    if(rk[a] == rk[b])
        rk[a]++;
}

int main(){
    cin>>n>>m>>p>>q;
    rk.resize(m+1);
    par.resize(m+1);
    for(int i = 1; i <= m; i ++){
     create(i);
    }

    for(int i = 1,x,y,v; i <= p; i++){
        cin>>x>>y>>v;
        a.pb({v,{x,y}});
        old+=v*m;
    }

    for(int i =0,x,y,v; i < q; i++){
        cin>>x>>y>>v;
        b.pb({v,{x,y}});
        old+=v*n;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(pair<int, pii> i : a){
        if(fnd(i.second.first) != fnd(i.second.second)){
            onion(i.second.first, i.second.second);
            r+=i.first;
        }
    }

    rk.resize(n+1);
    par.resize(n+1);
    for(int i = 1; i <= n; i ++){
     create(i);
    }

    for(pair<int, pii> i : b){
        if(fnd(i.second.first) != fnd(i.second.second)){
            onion(i.second.first, i.second.second);
            r+=i.first;
        }
    }


    cout<<old-r;

}
