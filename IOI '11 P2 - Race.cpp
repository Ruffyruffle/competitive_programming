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
#define MAXN 1000001
using namespace std;
bool done[MAXN];
int ans[MAXN>>1], sz[MAXN];
int ans2 = INF;
vector<pii> a[2000001];
stack<int> changed;
int k;
void dfs(int cur, int last){
    sz[cur] = 1;
    for(pii i : a[cur]){
        if(i.f == last || done[i.f]) continue;
        //cout<<i.f<<endl;
        dfs(i.f, cur);
        sz[cur]+=sz[i.f];
    }
}

void solve(int cur, int last, int d, int len){
    ans[d] = min(ans[d], len);
    cout<<cur<<" "<<d<<endl;
    changed.push(d);
    for(pii i : a[cur]){
        if(i.f == last || done[i.f] || d+i.s > k) continue;
        solve(i.f, cur, d + i.s, len+1);
    }
}

void solve2(int cur, int last, int d, int len){
    //cout<<k-(d)<<" "<<ans[k-(d)] + len<<endl;
    cout<<cur<<" "<<d<<endl;
    ans2 = min(ans2, ans[k-(d)] + len);
    for(pii i : a[cur]){
        if(i.f == last || done[i.f] || d+i.s > k) continue;
        solve2(i.f, cur, d + i.s, len+1);
    }
    //cout<<k<<endl;
}

int Cen(int cur, int last, int tot){
    //cout<<'a'<<endl;
    for(pii i : a[cur]){
        if(i.f == last || done[i.f]) continue;
        if(sz[i.f]<<1 > tot){
            return Cen(i.f, cur, tot);
        }
    }
    return cur;
}


void decomp(int rt){
    ans[0] = 0;
    dfs(rt, -1);
    if(sz[rt] == 1) return;
    int cen = Cen(rt, -1, sz[rt]);
    cout<<cen<<endl;
    done[cen] = 1;
    solve(a[cen][0].f,-1,a[cen][0].s,1); solve2(a[cen][1].f,-1,a[cen][1].s,1);
    ans2 = min(ans2, ans[k]);

    while(!changed.empty()){
        ans[changed.top()] = INF;
        changed.pop();
    }

    //cout<<a[cen][1].f<<endl;
    for(pii i : a[cen]){
        //cout<<cen<<" "<<i.f<<endl;
        if(!done[i.f]) decomp(i.f);
    }
}
int best_path(int N, int K, int H[][2], int L[]){
    MEM(ans, INF);
    k=K;
    for(int i = 0; i < N-1; i++){
        a[H[i][0]].pb({H[i][1], L[i]});
        a[H[i][1]].pb({H[i][0], L[i]});
    }
    decomp(0);
    return (ans2 == INF ? -1: ans2);
}

int best_path(int N, int K){
    MEM(ans, INF);
    k=K;
    decomp(0);
    return (ans2 == INF ? -1: ans2);
}

int main(){
    freopen ("test (2).txt","r",stdin);
    int n,k;
    cin>>n>>k;
    for(int i = 0,x,y,z; i < n-1; i++){
        cin>>x>>y>>z;
        a[x].pb({y,z});
        a[y].pb({x,z});
    }
//    cout<<k<<endl;
    int an;
    cin>>an;
    cout<<best_path(n,k)<<" "<<an;
}
