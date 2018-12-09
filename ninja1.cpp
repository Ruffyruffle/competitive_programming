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
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,m;
vector<int> a[MAXN];
bool vis[MAXN];

bool dfs(int cur, int last){
    if(vis[cur] || cur == last) return true;
    vis[cur] = true;
    bool b = false;
    for(int i : a[cur]){
        if(i!=last)
            b = (b==1 ? 1 : dfs(i,cur));
    }
    return b;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(m);
    for (int i =0,x,y; i < m; i++){
        scan(x); scan(y);
        a[x].pb(y);
        a[y].pb(x);
    }
    cout<<(dfs(1,0) ? "YES" : "NO");
}
