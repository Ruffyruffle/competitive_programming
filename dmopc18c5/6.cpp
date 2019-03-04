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
#define MAXN 200001
using namespace std;
ll n,m,ans;
ll va[MAXN], wa[MAXN];

ll solve(ll mask, ll val, vector<ll> a, ll last, bool s){
    //cout<<val<<endl;
    if(last != -1){
        ll l = last;
        for(ll i = last+1; i < n; i++){
            if(a[i] != -1){
                l = i; break;
            }
        }
        if(s && l == last) return INF;
        if(last!= -1){
            if(s){
                swap(a[last], a[l]);
            }
            val+=abs(a[last] - wa[last]);
            a[last] = -1;
        }
        if(mask == (1<<n) - 1) return val;
    }
    ll ret = INF;
    for(ll i = 0; i < n; i++){
        if(!(mask&(1<<i))){
            ll next = mask^(1<<i);
            ret = min(ret, solve(next, val ,a,i,0));
            ret = min(ret, solve(next, val, a, i,1));
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n; vector<ll> a;
    for (ll i =0,v,w; i < n; i++){
        cin>>v>>wa[i];
        a.pb(v);
    }
    cout<<solve(0,0,a,-1,0);
}
