#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,q;
vector<int> a[MAXN];
int d[MAXN];
void bfs(int cur){
    MEM(d,INF);
    queue<int> q;
    q.push(cur); d[cur] = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int i : a[cur]){
            if(d[i] == INF){
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y); a[y].pb(x);
    }
    bfs(1);
    ll far = -1, len = -1;
    for(int i = 1; i <= n; i++){
        if(d[i] > len){
            len = d[i]; far = i;
        }
    }
    bfs(far); len = -1, far = -1;
    for(int i = 1; i <= n; i++){
        if(d[i] > len){
            len = d[i]; far = i;
        }
    }

    cout<<len;
}
