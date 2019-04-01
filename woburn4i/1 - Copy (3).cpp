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
int n,m,ans,k;
vector<int> a[MAXN];
int vis[MAXN];
int key; string s;

void dfs(int cur, int last){
    vis[cur] = key;
    for(int i : a[cur]){
        if(vis[i] || last == i || s[cur] != s[i]) continue;
        dfs(i,cur);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    cin>>s;
    s = " "+s;
    for(int i = 0,x,y; i < m; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    for(int j = 1; j <= n; j++){
        if(!vis[j]){
            key++;
            dfs(j,-1);
        }
    }
    for(int i = 0,x,y; i < k; i++){
        cin>>x>>y;
        if(vis[x] == vis[y] && vis[x] != 0) ans++;
    }
    cout<<ans;
}
