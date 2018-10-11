#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 100001
using namespace std;
int n, m, k;
bool visited[MAXN];
vector<int> f[MAXN], gift;
int dis1[MAXN];
int dis2[MAXN];
int a, b, x, y;

void solve(int cur, int *dis){
    queue<int> d;
    d.push(cur);
    dis[cur] = 0;

    while(!d.empty()){
        cur = d.front();

        for(int i = 0; i<(int)f[cur].size();i++){
            int next = f[cur][i];
            if (dis[next]==-1){
                dis[next] = dis[cur]+1;
                d.push(next);
            }
        }
        d.pop();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>a>>b;
    for(int i = 0; i<k; i++){ cin>>x; gift.pb(x);}
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        f[x].pb(y); f[y].pb(x);
    }
    MEM(dis1, -1);
    MEM(dis2, -1);
    solve(a, dis1);
    solve(b, dis2);
//    for(int i = 1; i <= n; i++){
//        cout<<dis[i];
//    }
    int s, mn = INF;
    for(int i = 0; i < k; i++){
        s = gift[i];
        mn = min(mn, dis2[s] + dis1[s]);
    }
    cout<<mn;
}
