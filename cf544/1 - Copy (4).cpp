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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 400001
using namespace std;
ll n,m,ans;
ll mn[MAXN],gc[MAXN],co[MAXN];

void build(){
    for(int i = n-1; i > 0; i--){
        mn[i] = min(mn[i<<1], mn[i<<1|1]);
        gc[i] = __gcd(gc[i<<1], gc[i<<1|1]);
        co[i] = (gc[i]==gc[i<<1]?co[i<<1]:0) +
                (gc[i]==gc[i<<1|1]?co[i<<1|1]:0);
    }
}

void update(int i, int v){
    int t=i,tt=i;
    for(gc[t+=n]=v; t>1; t>>=1) gc[t>>1] = __gcd(gc[t], gc[t^1]);
    for(co[tt+=n]=1; tt>1; tt>>=1) co[tt>>1] = (gc[tt>>1]==gc[tt]?co[tt]:0) +
                                                (gc[tt>>1]==gc[tt^1]?co[tt^1]:0);
    for(mn[i+=n]=v; i>1; i>>=1) mn[i>>1] = min(mn[i], mn[i^1]);
}

int querya(int l, int r){
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) ret = __gcd(ret,gc[l++]);
        if (r&1) ret = __gcd(ret,gc[--r]);
    }
  return ret;
}
int queryb(int l, int r){
    int ret = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) ret = min(ret,mn[l++]);
        if (r&1) ret = min(ret,mn[--r]);
    }
  return ret;
}
int queryc(int l, int r, int gcd){
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) ret += (gcd==gc[l]?co[l++]:0);
        if (r&1) ret += (gcd==gc[--r]?co[r]:0);
    }
  return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0; i < n; i++){
        cin>>mn[n+i];
        gc[n+i] = mn[n+i];
        co[n+i] = 1;
    }
    build(); char c; int x,y;
    while(m--){
        cin>>c>>x>>y;
        if(c=='M'){
            cout<<queryb(x-1,y)<<endl;}
        else if(c=='G'){
            cout<<querya(x-1,y)<<endl;
        }else if(c=='Q'){
            cout<<queryc(x-1,y,querya(x-1,y))<<endl;}
        else{
            update(x-1,y);
        }
    }
}
