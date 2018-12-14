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
#define MAXN 1000000
using namespace std;
int n,m,ans,q, d[MAXN];
bool vis[MAXN];
vector<pii> a[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i =0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        a[x].pb({y,v});
        a[y].pb({x,v});
    }

    int last;
    int cur;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        cur = q.front(); q.pop();
        for(pii i : a[cur]){
            if(!vis[i.f]){
                last = i.f;
                q.push(i.f);
                vis[i.f] = 1;
            }
        }
    }
    q.push(last);
    MEM(d,INF);
    d[last] = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(pii i : a[cur]){
            if(d[i.f] > d[cur] + i.s){
                d[i.f] = d[cur] + i.s;
                q.push(i.f);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == INF){
            d[i] = 0;
            ans++;
        }
        ans = max(ans, d[i]);
    }
    cout<<ans;
    }


//int n,m,ans,q, lid[MAXN], big[MAXN], big2[MAXN], dp[MAXN];
//vector<pii> a[MAXN];
//
//void dfs(int cur, int last){
//    for(pii i: a[cur]){
//        if(i.f == last) continue;
//        dfs(i.f,cur);
//        if(big[i.f] + i.s > big[cur]){
//           big2[cur] = big[cur];
//           big[cur] = big[i.f] + i.s;
//           lid[cur] = i.f;
//        }
//        else if (big[i.f] + i.s > big2[cur]){
//            big2[cur] = big[i.f] + i.s;
//        }
//    }
//}
//
//void dfs2(int cur, int last){
//    for(pii i : a[cur]){
//        if(last == i.f) continue;
//        if(i.f == lid[cur])
//            dp[i.f] = max(dp[cur], big2[cur]) + i.s;
//        else
//            dp[i.f] = max(dp[cur], big[cur]) + i.s;
//        dfs2(i.f,cur);
//    }
//    dp[cur] = max(dp[cur], big[cur]);
//}
//
//int main(){
//    cin.sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    cin>>n>>m>>q;
//    for (int i =0,x,y,v; i < m; i++){
//        cin>>x>>y>>v;
//        a[x].pb({y,v});
//        a[y].pb({x,v});
//    }
//    dfs(1,-1);
//    dfs2(1,-1);
//    ans = (q==1 ? 0 : INF);
//    int d = 0;
//    for(int i = 1; i <= n; i++){
//        if(dp[i] == 0){
//            d++;
//            dp[i] = ans;
//        }
//        ans = (q==1 ? max(ans, dp[i]) : min(ans,dp[i]));
//    }
//    cout<<(q==1 ? ans+d : ans);
//}
