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
typedef std::pair<int, double> pii;
typedef std::pair<int, pii> piii;

const double INF = 0x3f3f3f3f;
#define MAXN 1001
using namespace std;
int n,m,ans;
vector<pii> a[MAXN];
double d[MAXN];
int bk[MAXN];
int main(){
    fill(begin(d), end(d), INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m; double v;
    for (int i =0,x,y,z; i < m; i++){
        cin>>x>>y>>z>>v;
        a[x].pb({y,(z/v)*60});
        a[y].pb({x,(z/v)*60});
    }

    queue<int> q;
    int cur; q.push(1);
    d[1] = 0;
    while(!q.empty()){
        cur=q.front(); q.pop();
        for(pii i: a[cur]){
            if(i.s + d[cur] < d[i.f]){
                d[i.f] = i.s + d[cur];
                q.push(i.f);
                bk[i.f] = cur;
            }
        }
    }
    bk[1] = -1, cur = n;
    while(cur != -1){
        cur = bk[cur];
        ans++;
    }
    cout<<ans-1<<endl<<round(d[n] * (1/0.75) - d[n]);





}
