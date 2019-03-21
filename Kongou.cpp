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
#define MAXN 2002
using namespace std;
int n,m,ans,t;
int order[MAXN];
vector<int> a[MAXN][MAXN];//num, adj
vector<int> v[MAXN];
bool vis[MAXN];
int low[MAXN], num[MAXN], par[MAXN];
int ti;

void dfs(int cur, int last, int f){
    vis[cur] = 1;
    par[cur] = last;
    num[cur] = low[cur] = ti++;
    bool fi = 1;
    //cout<<order[f]-1<<" "<<order[f+1]-1<<endl;
    for(int j = f; j < f+2; j++){
        for(int i : a[order[j]-1][cur]){
            //if(last == i) continue;
            if(!vis[i]){
                dfs(i,cur,f);
                low[cur] = min(low[cur], low[i]);
                if(low[i] > num[cur]) ans++;
            }
            if(fi && i == par[cur]) fi = 0;
            else low[cur] = min(low[cur], num[i]);
        }
    }

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>t;
    for (int i =0; i <= t; i++){
        cin>>order[i];
    }
    for (int i =0,k,x,y; i < m; i++){
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>x>>y;
            a[i][x].pb(y);
            a[i][y].pb(x);
            v[i].pb(x); v[i].pb(y);
        }
    }
    for (int i =0; i < t; i++){
        MEM(vis, 0); MEM(low, INF); MEM(par, -1); ti = 1;
        ans = 0;
        //cout<<order[i-1]<<endl;
        for(int &j : v[order[i]-1]){
            if(!vis[j]) dfs(j,-1,i);
        }
        for(int &j : v[order[i+1]-1]){
            if(!vis[j]) dfs(j,-1,i);
        }
        cout<<ans<<endl;
    }



}
