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
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,m,d;
vector<int> par, rk;
vector<pair<pii, pii> >a;
bool old[200001];
bool rev[200001];


void create(){
    for(int i = 0; i <= n ; i ++){
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
    if(a==b) return;
    if(rk[a] < rk[b]){
        swap(a,b);
    }
    par[b] = a;
    if(rk[a] == rk[b])
        rk[a]++;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>d;
    rk.resize(n+1);
    par.resize(n+1);
    create();
    for(int i = 1,x,y,v; i <= m; i++){
        cin>>x>>y>>v;
        a.pb({{v,i},{x,y}});
        old[i] = (i < n ? true : false);
        //cout<<i;
    }
    sort(a.begin(), a.end());
    vector<pair<pii,pii>> c;
    int ans = 0, big = 0;
    for(pair<pii,pii> i : a){
        if(fnd(i.second.second) != fnd(i.second.first)){
            rev[i.first.second] = true;
            big = max(big, i.first.first);
            onion(i.second.first, i.second.second);
            c.pb(i);
            if(!old[i.first.second]) ans++;
        }
    }
//
//    create();
//    vector<pair<pii,pii>> b;
    if(d > 0){
        for(auto i : a){
            if((d >= i.f.f || i.f.f == big) && old[i.f.s] && !rev[i.f.s]){
                cout<<ans-1; return 0;
            }
        }
    }

    cout<<ans;
}
