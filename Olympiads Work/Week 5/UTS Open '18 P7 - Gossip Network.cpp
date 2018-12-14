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
#define MAXN 10000
using namespace std;
vector<int> a[MAXN];
vector<int> b[MAXN];
bool done[MAXN];
int pop[MAXN], sz[MAXN],n,q;
void dfs(int cur, int last){
    sz[cur] = 1;
    for(int i : a[cur]){
        if(i!= last && !done[i]){
            dfs(i,cur); sz[cur]+=sz[i];
        }
    }
}
int Cen(int cur, int last, int tot){
    for(int i : a[cur]){
        if(i == last || done[i]) continue;
        if(sz[i]*2 > tot){
            return Cen(i, cur, tot);
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

int decomp(int rt){
    int cen = Cen(rt);
    for(int i : a[cen]){
        if(!done[i]){
            int sub = decomp(i);
            b[cen].pb(sub);
            b[sub].pb(cen);
        }
    }
    return cen;
}

/*
16 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 4 2 4 3 4 4 5 5 6 6 7 7 8 7 9 6 10 10 11 11 12 11 13 12 14 13 15 13 16

*/


int main(){
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>pop[i];
    }
    for(int i = 0,x,y; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    int root = decomp(1);
//    queue<int> f;
//    f.push(root);
//    int cur = 0;
//    bool vis[100];
//    MEM(vis, 0);
//    while(!f.empty()){
//        cur = f.front(); f.pop();
//        for(int i : b[cur]){
//            if(vis[i]) continue;
//            cout<<cur<<" "<<i<<endl;
//            f.push(i);
//            vis[i] = 1;
//        }
//    }

}

