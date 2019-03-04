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
int n,m, v[MAXN],l[MAXN],p[MAXN];
vector<int> a[MAXN];
bool vis[MAXN];
int c=1; vector<int> ans;
void dfs(int cur){
    //cout<<cur<<endl;
    vis[cur]=1; v[cur] = c++; l[cur] = v[cur];
    for(int i : a[cur]){
        if(!vis[i]){
            p[i] = cur;
            dfs(i);
            l[cur] = min(l[i], l[cur]);
            if(p[cur] == 0){
                if(a[i].size() > 1) ans.pb(cur);
            }
            else if(l[i] >= v[cur]) ans.pb(cur);
        }
        if(vis[i] && i != p[cur]){
            l[cur] = min(v[i],l[cur]);
        }
    }
}
int main(){
    //MEM(l,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y; i < m; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    UNI(ans);  sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i : ans){
        cout<<i<<endl;
    }



}
