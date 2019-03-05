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
#define MAXN 200001
using namespace std;
int n,m,ans;
int bit[MAXN];
bool done[MAXN];
int sz[MAXN], tot;
stack<int> changed;
vector<int> a[MAXN]; vector<pii> kinako;//[MAXN];
string t; int lk,rk,lc,rc;
void add(int i, int v){
    while(MAXN > i){
        bit[i]+=v;
        i+=(i&-i);
    }
}

int sum(int i){
    int ret=0;
    while(i>0){
        ret+=bit[i];
        i-=(i&-i);
    }
    return ret;
}

void dfs(int cur, int last){
    sz[cur] = 1;
    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        dfs(i,cur);
        sz[cur]+=sz[i];
    }
}

int centroid(int cur, int last){
    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        if(sz[i]<<1 > tot) return centroid(i,cur);
    }
    return cur;
}

void solve(int cur, int last, int ki=0, int cr=0){
    if(t[cur] == 'K') ki++;
    else cr++;
    if(rk < ki || rc < cr) return;

    if(ki>=lk&&cr>=lc) ans++;

    //if(kinako[ki].size() == 0) changed.push(ki);
    kinako.pb({ki,cr});
    //cout<<ki<<" "<<cr<<endl;

    for(int &i : a[cur]){
        if(i == last || done[i]) continue;
        solve(i, cur, ki, cr);
    }
}

//void solve2(int cur, int last, int ki, int cr, bool first){
//    if(t[cur] == 'K') ki++;
//    else cr++;
//
//    if(first) ki--;
//    else cr--;
//
//    if(rk < ki || rc < cr) return;
//    //cout<<ki<<" "<<rk-ki<<endl;
//    for(int i = rk - ki; i >= 0 && ki + i >= lk; i--){
//        for(int &j : kinako[i]){
//            if(cr + j >= lc && rc >= cr + j) ans++;
//        }
//    }
//
//    if(first) ki++;
//    else cr++;
//
//    for(int &i : a[cur]){
//        if(i == last || done[i]) continue;
//        solve2(i, cur, ki, cr,first);
//    }
//}
//


void decomp(int rt){
    dfs(rt,-1); tot = sz[rt];
    int cen = centroid(rt, -1);
    done[cen] = 1;
    //cout<<sz[cen]<<endl;

    int ki=0, cr=0;
    if(t[cen] == 'K') ki++;
    else cr++;

    //if(sz[cen] == 1){
        if(ki>=lk&&rk>=ki&&cr>=lc&&rc>=cr) ans++;
    //}
    vector<pii> p;

    for(int i = 0; i < a[cen].size(); i++){
        if(done[a[cen][i]]) continue;
        //if(i!=0) solve2(a[cen][i], -1, ki, cr, ki);
        solve(a[cen][i], -1, ki, cr);
        for(pii &j : kinako){
            p.pb(j);
        }
        //work sliding window for all points. account for centroid value.
    }

    cout<<endl;
    for(int i = 0; i < p.size(); i++){
        cout<<p[i].f<<" "<<p[i].s<<endl;
    }

    for(int &i : a[cen]){
        if(!done[i]) decomp(i);
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>lk>>rk>>lc>>rc;
    cin>>t; int x,y;
    for (int i =0; i < n-1; i++){
        cin>>x>>y; x--; y--;
        a[x].pb(y); a[y].pb(x);
    }
    decomp(0);
    cout<<ans;
}
