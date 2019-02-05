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
int n,m,ans,q,d[MAXN];
vector<int> par,rk,a[MAXN];
inline void create(int a){
    par[a] = a;
    rk[a] = 0;
}
int fnd(int a){
    if(par[a] == a) return a;
    return par[a] = fnd(par[a]);
}

void onion(int a, int b){
    a = fnd(a); b=fnd(b);
    if(a!=b){
        if(rk[b] > rk[a]){
            swap(a,b);
        }
        if(rk[b] == rk[a]){
            rk[a]++;
        }
        par[b] = a;
    }
}
int solve(int x,int y){
    if(fnd(x) != fnd(y)) return -1;
    stack<int> changed;
    d[x] = 0;
    queue<int> q; q.push(x);
    while(!q.empty()){
        x = q.front(); q.pop();
        if(x==y){
            int t = d[x];
            while(!changed.empty()){
                d[changed.top()] = INF;
                changed.pop();
            }
            return t;
        }
        for(int i : a[x]){
            if(d[i] == INF){
                d[i] = d[x] + 1;
                q.push(i);
                changed.push(i);
            }
        }
    }

}
int main(){
    MEM(d,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q; int x,y;
    par.resize(n+1); rk.resize(n+1);
    for(int i = 1; i <= n; i++) create(i);
    for (int i =0; i < m; i++){
        cin>>x>>y; a[x].pb(y);a[y].pb(x);
        onion(x,y);
    }
    while(q--){
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }
    //cout<<fnd(3);




}
