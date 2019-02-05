#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 30001
using namespace std;
ll n,m,ans, mn[2*MAXN], lz[MAXN];
int h;

inline void apply(int i, int v){
    mn[i]+=v;
    if(n>i) lz[i] += v;
}

inline void build(){
  for (int i = n - 1; i > 0; i--) mn[i] = min(mn[i<<1], mn[i<<1|1]);
}

inline void pushup(int i){
    while(i>1) i>>=1, mn[i] = min(mn[i<<1], mn[i<<1|1])+lz[i];
}

inline void pushdown(int n){
    for(int s = h; s > 0; s--){
        int i = n>>s;
        if(lz[i]){
            apply(i<<1, lz[i]);
            apply(i<<1|1, lz[i]);
            lz[i] = 0;
        }
    }
}

inline void rinc(int l, int r, int v){
    l+=n, r+=n;
    int l2=l, r2=r;
    for(;l<r; l>>=1,r>>=1){
        if(l&1) apply(l++, v);
        if(r&1) apply(--r, v);
    }
    pushup(l2); pushup(r2-1);
}
ll rquery(int l, int r){
    l+=n,r+=n;
    pushdown(l); pushdown(r-1);
    ll ans = INF;
    for(;l<r;l>>=1,r>>=1){
        if(l&1) ans = min(ans, mn[l++]);
        if(r&1) ans = min(ans, mn[--r]);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    h = sizeof(int) * 8 - __builtin_clz(n);
    for (int i =0,x; i < n; i++){
        cin>>mn[n+i];
    }
    build();
//    cout<<"a";
//    rinc(0,2,1);
//    cout<<"b";
//    rquery(1,2);
//    cout<<"c";
    int l,r,x;
    while(m--){
        cin>>l>>r>>x;
        l--;
        rinc(l,r,-x);
        cout<<max(0ll,rquery(l,r))<<" "<<max(rquery(0,n), 0ll)<<endl;
    }
}
