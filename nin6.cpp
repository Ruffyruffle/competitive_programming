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
#define MAXN 1000000
using namespace std;
ll n, p[MAXN], d[MAXN], vis[MAXN],m,a,b;
vector<pii> ad[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>a>>b;
    for (int i =0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        ad[x].pb({y,v});
        ad[y].pb({x,v});
    }
    MEM(d, INF);
    d[a] = 0; p[a] = 1; vis[a] = 1;
    queue<int> f;
    f.push(a);
    int cur = a;

    for(int j = 0; j < n; j++){
        for(pair<pii> i : a){
            b[i.first] = min(b[i.first], b[i.first.second]);
        }
    }

    cout<<d[b]<<endl<<p[b];
}
