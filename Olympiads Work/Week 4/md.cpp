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
#define MAXN 100002
using namespace std;
int n,m,ans,k, mark[MAXN];
vector<pair<int, pair<int, int> > > a;
vector<pii> b[MAXN];
vector<pii> mst[MAXN];
vector<int> par, rk;
vector<int> s;
void create(int v){
    par[v] = v;
    rk[v] = 0;
}

int fnd(int v){
    if(v==par[v]) return v;
    return par[v] = fnd(par[v]);
}

void onion(int a, int b){
    a = fnd(a);
    b=fnd(b);
    if(a!=b){
        if(rk[a] < rk[b])
            swap(a,b);
        par[b] = a;
        if(rk[a]==rk[b]) rk[a]++;
    }
}

void check(int cur, int last){
    for(pii i : mst[cur]){
        if(i.s == last) continue;
        check(i.s, cur);
        mark[cur] += mark[i.s];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 0,x; i < k; i++){
        cin>>x; s.pb(x);
        mark[x] = 1;
    }
    par.resize(n+1);
    rk.resize(n+1);
    for (int i =1,x,y,z; i <= m; i++){
        cin>>x>>y>>z;
        a.pb({z,{x,y}});
    }
    for(int i = 1; i <=n; i++){
        create(i);
    }

    sort(a.begin(), a.end());
    for(pair<int, pair<int, int> > i: a){
        if(fnd(i.second.first) != fnd(i.second.second)){
            mst[i.second.first].pb({i.first, i.second.second});
            mst[i.second.second].pb({i.first, i.second.first});
            onion(i.second.first, i.second.second);
        }
    }

    check(s[0],-1);
    for(int i = 1; i <=n; i++){
        create(i);
    }
    int mx = -1;
    for(pair<int, pair<int, int> > i: a){
        if(fnd(i.second.first) != fnd(i.second.second)){
            if(mark[i.second.first] <= 0 || mark[i.second.second] <= 0)
                continue;
            mst[i.second.first].pb({i.first, i.second.second});
            mst[i.second.second].pb({i.first, i.second.first});
            onion(i.second.first, i.second.second);
            mx = max(mx, i.first);
        }
    }





    for(int i : s){
        cout<<mx<<" ";
    }


}
