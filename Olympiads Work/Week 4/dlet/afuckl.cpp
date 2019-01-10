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
#define MAXN 200001
using namespace std;
int n,m;
bool vis[MAXN];
vector<int> a[MAXN];
vector<int> b,c;
vector<pii> d;
bool v = 0;

//bool dfs(int cur, int last, int root){
//    if(cur == root && v) return true;
//    bool g=0;
//    for(int i : a[cur]){
//        v = 1;
//        if(last == i) continue;
//        g = (g==1?1:dfs(i,cur,root));
//    }
//    return g;
//}
//bool dfs2(int cur, int last){
//    cout<<cur<<" ";
//    vis[cur] = 1;
//    for(int i : a[cur]){
//        if(last == i || vis[i]) continue;
//        dfs2(i,cur);
//    }
//}
//void dfs2(int cur, int last){
//    cout<<cur<<" ";
//    vis[cur] = 1;
//    for(int i : a[cur]){
//        if(last == i || vis[i]) continue;
//        dfs2(i,cur);
//    }
//}
void dfs(int cur, int last){
    c.pb(cur);
    for(int i : a[cur]){
        if(last == i || vis[i]) continue;
        dfs(i,cur);
        vis[cur] = 1;
    }
}
void dfs2(int cur, int last){
    b.pb(cur);
    for(int i : a[cur]){
        if(last == i || vis[i]) continue;
        dfs2(i,cur);
        vis[i] = 1;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int q,w;
    d.pb({0,0});
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
//        if(i == 0){
//            q = x; w = y;
//        }
        a[x].pb(y);
        a[y].pb(x);
        d.pb({x,y});
    }
    vis[1] = 1;
    dfs(1,-1);
    a[1].erase(a[1].begin());
    MEM(vis,0);
    vis[1] = 1;
    dfs2(1,-1);
    bool f = 1;
    for(int i = 0; i < n; i++){
        if((b[(i+1) % n] != d[b[i]].f && b[(i+1) % n] != d[b[i]].s) || (b[(i+2) % n] != d[b[i]].f && b[(i+2) % n] != d[b[i]].s)){
            f = 0; break;
        }
    }
    //cout<<b.size()<<endl;
    if(f){
        for(int i = 0; i < n; i++){
            cout<<b[i]<<" ";
        }
    }
    else{
        for(int i = 0; i < n; i++){
            cout<<c[i]<<" ";
        }
    }
//    if(dfs(q,-1,q)){
//        v = 0;
//        //cout<<"a";
//        dfs2(q,-1,q);
//    }else{
//        v = 0;
//        dfs2(w,-1,w);
//    }
    //dfs2(3,-1);
    //MEM(ans, -1);

}
