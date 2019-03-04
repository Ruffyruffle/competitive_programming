#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;
typedef std::pair<ll, pii> piii;

const ll INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ll n,m,ans;
vector<piii> a;
vector<ll> par, rk;
void create(ll v){
    par[v] = v;
    rk[v] = 0;
}

ll fnd(ll v){
    if(v==par[v]) return v;
    return par[v] = fnd(par[v]);
}

void onion(ll a, ll b){
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
    for (ll i =1,x,y,z; i <= m; i++){
        cin>>x>>y>>z;
        a.pb({z,{x,y}});
    }
    for(ll i = 1; i <=n; i++){
        create(i);
    }
    sort(a.begin(), a.end());
    for(pair<ll, pair<ll, ll> > i: a){
        if(fnd(i.s.f) != fnd(i.s.s)){
            onion(i.s.f, i.s.s);
            ans+=i.f;
        }
    }
    cout<<ans;
}
