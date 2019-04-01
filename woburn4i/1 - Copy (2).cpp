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
ll n,m,ans,k;
vector<pii> a;
//void solve(ll cur)
vector<pii> cur;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (ll i =0,x,y; i < n; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    ll r = 1;
    ll t = a[0].f;
    a.pb({a[0].s,a[0].f});
    ans = a[0].f;
        ll l = INF;
    ll c=a[0].f; ll last = 0;
    while(n > r || !cur.empty()){
        if(l!=INF){
            last = abs(c-l);
            ans+=last;
            c = l;
            for(pii&i : cur){
                if(i.s == l) i.s=-1;
            }
        }
        else{
            r++;
            last = abs(c-a[r].f);
            ans+=last;
            c = a[r].f;
        }
        l=INF;
        for(pii &i : cur){
            if(i.s==-1) continue;
            i.f-=last;
            if(0>=i.f) l = min(l,i.s);
        }

    }
    cout<<ans+(m-c);



}
