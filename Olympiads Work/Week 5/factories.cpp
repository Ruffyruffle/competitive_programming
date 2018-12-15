//#include "factories.h"
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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 500001
using namespace std;
vector<pii> a[MAXN];
//vector<int> b[MAXN];
bool done[MAXN];
int sz[MAXN],n,q,lvl[MAXN], par[MAXN], root;
ll d[20][MAXN];
ll ans[MAXN];
stack<int> changed;
void dfs(int cur, int last){
    sz[cur] = 1;
    for(pii i : a[cur]){
        if(i.f!= last && !done[i.f]){
            dfs(i.f,cur); sz[cur]+=sz[i.f];
        }
    }
}
int Cen(int cur, int last, int tot){
    for(pii i : a[cur]){
        if(i.f == last || done[i.f]) continue;
        if(sz[i.f]*2 > tot){
            return Cen(i.f, cur, tot);
        }
    }
    return cur;
}

int Cen(int cur){
    dfs(cur, -1);
    int cen = Cen(cur, -1, sz[cur]);
    done[cen] = 1;
    return cen;
}

void minDis(int cur, int last, ll dis, int lvl){
    d[lvl][cur] = min(d[lvl][cur], dis);
    for(pii i : a[cur]){
        if(i.f==last||done[i.f]) continue;
        minDis(i.f,cur,dis+i.s,lvl);
    }
}

int decomp(int rt, int lv){
    int cen = Cen(rt);
    lvl[cen] = lv;
    minDis(cen,-1,0,lv);
    for(pii i : a[cen]){
        if(!done[i.f]){
            int sub = decomp(i.f, lv + 1);
            par[sub] = cen;
//            b[cen].pb(sub);
//            b[sub].pb(cen);
        }
    }
    return cen;
}

/*
16 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 4 2 4 3 4 4 5 5 6 6 7 7 8 7 9 6 10 10 11 11 12 11 13 12 14 13 15 13 16
*/

void Init(int N, int A[], int B[], int D[]){
    MEM(d, INF);
    MEM(ans, INF);
    for(int i = 0; i < N-1; i++){
        a[A[i]].pb({B[i],D[i]});
        a[B[i]].pb({A[i],D[i]});
    }
    root = decomp(1,0);
    par[root] = -1;
}
long long Query(int S, int X[], int T, int Y[]){
    for(int k = 0; k < S; k++){
        int i = X[k];
        int cur = i;
        while(cur!=-1){
            changed.push(cur);
            ans[cur] = min(ans[cur],d[lvl[cur]][i]);
            cur = par[cur];
        }
    }
    ll ret = INF;
    for(int k = 0; k < T; k++){
        int i = Y[k];
        int cur = i;
        while(cur!=1){
            ret = min(ret, ans[cur] + d[lvl[cur]][i]);
            cur = par[cur];
        }
    }
    while(!changed.empty()){
        ans[changed.top()] = INF;
        changed.pop();
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n], b[n],d2[n];
    for(int i = 0; i < n-1;i++){
        cin>>a[i]>>b[i]>>d2[i];
    }
    Init(n,a,b,d2);
//    for(int i = 0; i < n; i++){
//        cout<<lvl[i]<<endl;
//    }
    int s,t;
    for(int i = 0; i < q; i++){
        cin>>s>>t;
        int x[s], y[t];
        for(int j = 0; j < s; j++){
            cin>>x[j];
        }
        for(int j = 0; j < t; j++){
            cin>>y[j];
        }
        cout<<Query(s,x,t,y)<<endl;
    }


}

