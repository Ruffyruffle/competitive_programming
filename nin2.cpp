#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,m;
vector<pii> a;
vector<int> par, rk;
int cn[MAXN];
void create(int v){
    par[v] = v;
    rk[v] = 0;
}

int fnd(int v){
    if(v==par[v]) return v;
    return par[v] = fnd(par[v]);
}

void onion(int a, int b){
    a = fnd(a);
    b=fnd(b);
    if(a!=b){
        if(rk[a] < rk[b])
            swap(a,b);
        par[b] = a;
        if(rk[a]==rk[b]) rk[a]++;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    par.resize(n+1);
    rk.resize(n+1);
    for(int i = 0; i <= n; i++){create(i);}
    for(int i = 0,x,y; i < m; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    for(pii i : a){
        onion(i.first, i.second);
    }

    for(int i = 1; i <= n; i++){
        cn[fnd(i)]++;
    }
    ll ans = n;

    for(int i = 1; i <=n; i++){
        ans+= cn[i] * cn[i]-1;
    }
    cout<<ans;
}
