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
//typedef long long int;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m,ans,c,k;
vector<pii> a[MAXN];
int ca[MAXN], ct[MAXN], wt[MAXN];

void dfs(int cur, int last, int w){
    ct[cur]=ca[cur];
    wt[cur] = w;
    for(pii i: a[cur]){
        //cout<<i.f<<" ";
        if(i.f==last) continue;
        dfs(i.f,cur,i.s);
        //wt[cur]+=i.s;
        wt[cur]+=wt[i.f];
        ct[cur]+= ct[i.f];
    }
    if(ct[cur] >= c && wt[cur] <= k && cur!= 1) ans++;
    //cout<<cur<<endl;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>c>>k;
    for(int i = 1; i <= n; i++){
        cin>>ca[i];
    }
    for (int i =0,x,y,v; i < n-1; i++){
        cin>>x>>y>>v;
        a[x].pb({y,v});
        a[y].pb({x,v});
        //cout<<x<<" "<<y<<endl;
    }
    dfs(1,-1,0);
    cout<<ans;
}
