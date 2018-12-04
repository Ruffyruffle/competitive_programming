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

const int INF = 0x3f3f3f3f;
#define MAXN 1000010
using namespace std;
ll n,q;
ll bit[MAXN];

void add(int i, int v){
    while(i<= MAXN){
        bit[i]+=v;
        i+=(-i&i);
    }
}
ll sum(int i){
    ll ans = 0;
    while(i>0){
        ans+=bit[i];
        i-= (i&-i);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);scan(q);
    unordered_map<ll, int> o;
    vector<ll> s;
    vector<ll> f;

    for (ll i =1,x; i <= n; i++){
        scan(x);
        o[x] = i;
        s.pb(x);
        f.pb(-x);
    }
    int c;
    for(ll i = 0,x,y,v; i < q; i++){
        scan(c);
        if(c==1){
            scan(x); scan(y); scan(v);
            add(o[*lower_bound(s.begin(), s.end(), x)], v);
            add(o[*--upper_bound(s.begin(), s.end(), y)]+1, -v);
        }
        else{
            scan(x);
            cout<<sum(x)<<'\n';
        }
    }
}
