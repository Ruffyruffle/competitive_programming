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
#define MAXN 1001
using namespace std;
int n,m,ans;

vector<int> par, rk;
vector<pii> mst[MAXN];
vector<piii> a;

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
        par[b] = a;
        if(rk[b] == rk[a]){
            rk[a]++;
        }
    }
}
inline bool cmp(piii a, piii b){return a.f > b.f;}
void gen(){
    sort(a.begin(), a.end(),cmp);
    for(int i = 1; i <= n; i++){
        mst[i].clear();
    }
    for (int i = 1; i <= n; i++){
        create(i);
    }
    for(piii i : a){
        if(fnd(i.s.f)!=fnd(i.s.s)){
            onion(i.s.f,i.s.s);
            mst[i.s.f].pb({i.f,i.s.s});
            mst[i.s.s].pb({i.f,i.s.f});
        }
    }
}

void solve(int x, int y, int v){
    queue<pii> q;
    q.push({x,-1});
    while(!q.empty()){
        x = q.front().f; int last = q.front().s; q.pop();
        if(x==y) {cout<<1<<endl; return;}
        for(pii i : mst[x]){
            if(i.f < v||i.s == last) continue;
            //cout<<x<<" "<<i.f<<" "<<i.s<<endl;
            q.push({i.s,x});
        }

    }
    cout<<0<<endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    par.resize(n+1); rk.resize(n+1);
    int x,y,v;
    for (int i = 1; i <= m; i++){
        cin>>x>>y>>v;
        a.pb({v,{x,y}});
    }
    bool d = 0;
    gen();
    int q; cin>>q;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x>>y;
            a[x-1].f=y;
            gen();
        }
        else{
            cin>>x>>y>>v;
            //if(!d){
            //    gen();
            //    d= 1;
            //}
            solve(x,y,v);
        }
    }
}
