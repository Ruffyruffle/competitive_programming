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
#define MAXN 100001
using namespace std;
int n,m,ans,k,f,ans3;
vector<int> g, a[MAXN];
int d[MAXN],mark[MAXN], d2[MAXN];

void dfs(int cur, int last){
    for(int i : a[cur]){
        if(i == last) continue;
        d[i] = d[cur] + 1;
        dfs(i,cur);
    }
}

void check(int cur, int last){
    for(int i : a[cur]){
        if(i == last) continue;
        check(i, cur);
        mark[cur] += mark[i];
    }
}

void dfs2(int cur, int last){
    for(int i : a[cur]){
        if(i == last || mark[i] == 0) continue;
        ans++;
        dfs2(i,cur);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>f;
    for(int i = 0,x; i < k; i++){
        cin>>x; g.pb(x); mark[x] = 1;
    }
    mark[1] = 1;
    mark[f] = 1;
    for (int i =0,x,y; i < n-1; i++){
        cin>>x>>y; a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    check(1,-1);
    dfs2(1,-1);
//    dfs(f,-1);
//    int ans2 = INF;
//    for(int i = 1; i <= n; i++){
//        if(mark[i] > 0)
//            ans2 = min(ans2, d[i]);
//    }

    int anst = ans;
    MEM(mark, 0);
    for(int i : g){
        mark[i] = 1;
    }

    mark[1] = 1;
    check(1,-1);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(mark[i] > 0){
            cnt++;
        }
    }

    int mx = -1, mi;
    for(int i = 1; i <= n; i++){
        if(d[i] > mx && mark[i] > 0){
            mx = d[i];
            mi = i;
        }
    }
    ans3 = mx + (cnt - (mx+1)) * 2;
    //cout<<ans3<<endl;

    cout<<min(anst,ans3);


}
