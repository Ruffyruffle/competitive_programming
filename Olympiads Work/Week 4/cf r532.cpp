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
typedef std::pair<pii, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m,ans=1,k;
vector<piii> a;
bool b[100001];
int n,m;
vector<pair<int, pair<int, int> > > a;
vector<int> par, rk;
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

void dfs(int cur, int last){

    for()

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    par.resize(n+1);
    rk.resize(n+1);
    for (int i =1,x,y; i <= m; i++){
        cin>>x>>y>>w;
        a.pb({{i,w},{x,y}});
        b[y] = 1;
    }
    int root=-1;
    for(int i = 1; i<=n; i++){
        if(!b[y]){
            root = i;
            break;
        }
    }
    for(int i = 1; i <=n; i++){
        create(i);
    }
    sort(a.begin(), a.end());
    vector<int> mst;
    for(pair<int, pair<int, int> > i: a){
        if(fnd(i.second.first) != fnd(i.second.second)){
            mst.pb(i.first);
            onion(i.second.first, i.second.second);
        }
    }
    if(mst.size() != n-1) cout<<"Disconnected Graph";
    else for(int a: mst) cout<<a<<endl;
}



