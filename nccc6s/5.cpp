#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define MAXN 50004
using namespace std;
vector<pair<int,int>> a[MAXN];
int sz[MAXN], lvl[MAXN], par[MAXN], d[16][MAXN];
bool done[MAXN]; int ans[MAXN];
void dfs(int cur, int last){
    sz[cur] = 1;
    for(auto i : a[cur]){
        if(i.f != last && !done[i.f]){
            dfs(i.f,cur);
            sz[cur]+=sz[i.f];
        }
    }
}

void dfs2(int cur, int last, int dis, int lvl){
    d[lvl][cur] = dis;
    for(auto i : a[cur]){
        if(i.f==last||done[i.f]) continue;
        dfs2(i.f,cur, dis+i.s,lvl);
    }
}

int fnd(int cur, int last, int tot){
    for(auto i : a[cur]){
        if(i.f == last||done[i.f]) continue;
        if(sz[i.f]*2 > tot){
            return fnd(i.f, cur, tot);
        }
    }
    return cur;
}

int decomp(int rt, int lev){
    dfs(rt, -1);
    int cen = fnd(rt,-1,sz[rt]);
    done[cen] = 1;
    lvl[cen] = lev;
    dfs2(cen,-1,0,lev);
    for(auto i : a[cen]){
        if(!done[i.f]){
            int sub = decomp(i.f,lev + 1);
            par[sub] = cen;
        }
    }
    return cen;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y,v;
    while(m--){
        cin>>x>>y>>v;
        a[x].pb({y,v});
        a[y].pb({x,v});
    }
    int root = decomp(1,0);
    int q,a,b,ans2;
    cin>>q;
    stack<int> change;
    memset(ans,0x3f3f3f3f,sizeof(ans));
    par[root] = -1;
    while(q--){
        ans2 = 0x3f3f3f3f;
        cin>>a>>b;
        int cur = a;
        while(cur!=-1){
            change.push(cur);
            ans[cur] = min(ans[cur], d[lvl[cur]][a]);
            cur = par[cur];
        }
        cur = b;
        while(cur!=-1){
            ans2 = min(ans2, ans[cur] + d[lvl[cur]][b]);
            cur = par[cur];
        }
        while(!change.empty()){
            ans[change.top()] = 0x3f3f3f3f;
            change.pop();
        }
        cout<<ans2<<'\n';
    }


}
