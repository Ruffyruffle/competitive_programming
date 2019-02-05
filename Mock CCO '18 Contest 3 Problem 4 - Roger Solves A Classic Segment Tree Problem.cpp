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
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 50001
using namespace std;
int n,m,ans;
int mx[2*MAXN], mn[2*MAXN];

inline void build(){
    for(int i = n-1; i > 0; --i){
        mx[i] = max(mx[i<<1], mx[i<<1|1]);
        mn[i] = min(mn[i<<1], mn[i<<1|1]);
    }
}
void modify(int i, int v){
    int t = i;
    for(mx[t+=n]=v; t>1; t>>=1) mx[t>>1] = max(mx[t], mx[t^1]);
    for(mn[i+=n]=v; i>1; i>>=1) mn[i>>1] = min(mn[i], mn[i^1]);
}

int query(int l, int r){
    int lo=INF,hi=-1;
    for(l+=n,r+=n; r>l; l>>=1, r>>=1){
        if(l&1){
            lo = min(lo, mn[l]);
            hi = max(hi, mx[l++]);
        }
        if(r&1){
            lo = min(lo, mn[--r]);
            hi = max(hi, mx[r]);
        }
    }
    return hi-lo;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0; i < n; i++){
        cin>>mn[n+i];
        mx[n+i]=mn[n+i];
    }
    build();
    int x,y;
    while(m--){
        cin>>x>>y;
        cout<<query(x-1,y)<<endl;
    }



}
