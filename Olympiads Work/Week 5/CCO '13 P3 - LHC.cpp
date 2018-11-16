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
#define MAXN 400001
using namespace std;
int n;
vector<int> a[MAXN];
bool visited[MAXN];
ll h[MAXN], nh[MAXN];
ll ans = 0, ansn= 0;

int solve(int cur){
    visited[cur] = true;
    h[cur] = 0, nh[cur] = 1;
    for (int s : a[cur]){
        if(visited[s]) continue;
        solve(s);

        if(h[cur] + 1 + h[s] > ans){
            ans = h[cur] + 1 + h[s];
            ansn = nh[s] * nh[cur];
        }
        else if(h[cur] + 1 + h[s] == ans){
            ansn+=nh[s] * nh[cur];
        }

        if(h[s] + 1 > h[cur]){
            h[cur] = h[s] + 1;
            nh[cur] = nh[s];
        }
        else if (h[s] + 1 == h[cur]){
            nh[cur] += nh[s];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    MEM(visited, false);
    cin>>n;
    int x,y;
    for (int i =0; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    solve(1);
    cout<<ans+1<<" "<<ansn;
}
