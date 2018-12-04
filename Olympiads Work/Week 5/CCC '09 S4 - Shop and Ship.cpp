#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 5001
using namespace std;
int n,m,k,cur, dis;
char _;
vector<pii> a[MAXN];
int store[MAXN];
int d[MAXN];
int main(){
    MEM(d,INF); MEM(store,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(m);
    for (int i =0,x,y,w; i < m; i++){
        scan(x);scan(y);scan(w);
        a[x].pb({y,w});
        a[y].pb({x,w});
    }
    scan(k);
    for(int i = 0,x,w; i < k; i++){
        scan(x);scan(w);
        store[x] = w;
    }
    int x; scan(x);
    priority_queue<pii, vector<pii>, greater<pii>> f;
    f.push({0,x}); d[x] = 0;

    while(!f.empty()){
        dis = f.top().first;
        cur = f.top().second; f.pop();
        if (dis > d[cur]) continue;
        for(pii i : a[cur]){
            int di = dis + i.second;
            if(di < d[i.first]){
                d[i.first] = di;
                f.push({di, i.first});
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <=n; i++){
        ans = min(ans, d[i] + store[i]);
    }
    cout<<ans;
}
