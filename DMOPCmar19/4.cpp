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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 1000004
using namespace std;
ll n,m,ans,p;
ll sufp[MAXN], nump[MAXN];;
ll sufm[MAXN], numm[MAXN];
vector<pii> a;
ll b[MAXN],c[MAXN];
ll mx=INF,mi;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>p>>m;
    for (ll i =0,x,y; i < n; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    for (ll i =0,x; i < p; i++){
        cin>>x;
        b[x]++;
    }
    for(ll i = 1000001; i >= 0; i--){
        sufp[i] = sufp[i+1] + b[i] * i;
        nump[i] = nump[i+1] + b[i];
    }
    for (ll i =0,x; i < m; i++){
        cin>>x;
        c[x]++;
    }
    for(ll i = 1000001; i >= 0; i--){
        sufm[i] = sufm[i+1] + c[i] * i;
        numm[i] = numm[i+1] + c[i];
    }
    //cout<<b[39];
    //cout<<sufp[37]<<endl;
    for(int i = 0; i < n; i++){
        ll dmg = sufp[a[i].f] - nump[a[i].f] * a[i].f;
        dmg+=sufm[a[i].s] - numm[a[i].s] * a[i].s;
        //cout<<dmg<<endl;
        if(mx > dmg){
            mx = dmg;
            //cout<<i<<endl;
            mi = i;
        }
    }
    cout<<mi+1;

}
