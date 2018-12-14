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
#define MAXN 1000000
using namespace std;
int n,m;
bool in[MAXN];
int d[MAXN], d2[MAXN];
vector<pii> a[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        a[x].pb({y,v});a[y].pb({x,v});
    }
    MEM(d,INF);
    queue<int> f;
    int cur = 0;
    in[cur] = 1;
    d[cur] = 0;
    f.push(0);
    while(!f.empty()){
        cur = f.front(); f.pop();
        in[cur] = 0;
        for(pii i : a[cur]){
            if(d[i.f] > d[cur] + i.s){
                d[i.f] = d[cur] + i.s;
                if(!in[i.f]){
                    f.push(i.f);
                    in[i.f] = 1;
                }
            }
        }
    }
    MEM(d2,INF);
    cur = n-1;
    in[cur] = 1;
    d2[cur] = 0;
    f.push(n-1);
    while(!f.empty()){
        cur = f.front(); f.pop();
        in[cur] = 0;
        for(pii i : a[cur]){
            if(d2[i.f] > d2[cur] + i.s){
                d2[i.f] = d2[cur] + i.s;
                if(!in[i.f]){
                    f.push(i.f);
                    in[i.f] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, d[i] + d2[i]);
    }
    cout<<ans;
}
