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
#define MAXN 100001
using namespace std;
ll n,m,ans,tot;
vector<int> a[MAXN];
int sz[MAXN];
bool done[MAXN];
int num[MAXN];
int dp[19], dp2[19];
vector<int> p;
void dfs(int cur, int last = -1){
    sz[cur] = 1;
    for(int i : a[cur]){
        if(done[i] || last == i) continue;
        dfs(i,cur);
        sz[cur] += sz[i];
    }
}

int centroid(int cur, int last = -1){
    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        if(sz[i]<<1 > tot) return centroid(i,cur);
    }
    return cur;
}

void solve(int cur, int last, int dis){
    for(int i = 0; i < 18; i++){
        if(dis&(1<<i)) {dp[i]++;}// cout<<dis<<" "<<i<<endl;}
        else dp2[i]++;
    }
    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        solve(i,cur, dis^num[i]);
    }
}
void solve2(int cur, int last, int dis){
//    for(int &i : p){
//        ans+=dis^i;
//        //cout<<(dis^i)<<endl;
//    }
    for(int i = 0; i < 18; i++){
        if(dis&(1<<i)) {dp[i]+=dp2[i];}// cout<<dp2[i]<<endl;}
        //else dp2[i]+=dp[i];
    }
    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        solve2(i,cur, dis^num[i]);
    }
}

void decomp(int rt){
    MEM(dp,0); MEM(dp2,0);
    dfs(rt,-1); tot = sz[rt];
    int cen = centroid(rt, -1);
    done[cen] = 1;

    for(int i = 0; i < a[cen].size(); i++){
        if(done[a[cen][i]]) continue;
        if(i!=0) solve2(a[cen][i], -1, num[a[cen][i]]);
        if(i!=a[cen].size()) solve(a[cen][i], -1, num[cen]^num[a[cen][i]]);
    }
    //p.clear();
    for(int i = 0; i < 18; i++){
        ans+=dp[i] * pow(2,i);
    }

    for(int &i : a[cen]){
        if(!done[i]) decomp(i);
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =1; i <= n; i++){
        cin>>num[i];
        ans+=num[i];
    }
    for(int i = 0,x,y; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    decomp(1);
    cout<<ans;



}
