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
typedef std::pair<int, bool> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m,ans2,ans3; ll ans;
int sz[MAXN];
bool done[MAXN];
vector<pii> a[MAXN];
int tot; int dif[MAXN], dif2[MAXN]; stack<int> changed, changed2;

void dfs(int cur, int last = -1){
    sz[cur] = 1;
    for(pii &i : a[cur]){
        if(done[i.f] || last == i.f) continue;
        dfs(i.f,cur);
        sz[cur] += sz[i.f];
    }
}

int centroid(int cur, int last= -1){
    for(pii &i : a[cur]){
        if(done[i.f] || last == i.f) continue;
        if((sz[i.f]<<1) > tot) return centroid(i.f,cur);
    }
    return cur;
}

void solve(int cur, int last, int r, int b){
    if(abs(r-b)==1 && r+b!=1){
        ans++;
    }
    if(abs(r-b)==1) ans3++;
    if(r==b) ans2++;
    //cout<<r<<" "<<b<<" "<<ans3<<endl;
    if(r>b){
        if(dif[r-b]==0) changed.push(r-b);
        dif[r-b]++;
    }
    if(b>r){
        if(dif2[b-r]==0) changed2.push(b-r);
        dif2[b-r]++;
    }
    for(pii &i : a[cur]){
        if(done[i.f] || last == i.f) continue;
        if(i.s) solve(i.f,cur,r+1,b);
        else solve(i.f,cur,r,b+1);
    }
}
void solve2(int cur, int last, int r, int b){
    if(abs(r-b)==1) ans+=ans2;
    if(r==b) ans+=ans3;
    //cout<<cur<<" "<<r<<" "<<b<<" "<<ans3<<endl;
    //cout<<cur<<endl;
    if(r>b){
        //cout<<'r'<<r-b<<endl;
        ans+=dif2[r-b+1];
        ans+=dif2[r-b-1];
    }
    else if(b>r){
//        cout<<'b'<<b-r<<endl;
//        cout<<b-r+1<<endl;
        ans+=dif[b-r+1];
        ans+=dif[b-r-1];
    }

    for(pii &i : a[cur]){
        if(done[i.f] || last == i.f) continue;
        if(i.s) solve2(i.f,cur,r+1,b);
        else solve2(i.f,cur,r,b+1);
    }
}
void decomp(int rt){
    dfs(rt);
    tot = sz[rt];
    int cen = centroid(rt);
    //cout<<cen<<endl<<endl;;
    done[cen] = 1;
    if(sz[cen] == 1) return;
    for(int i = 0; i < a[cen].size(); i++){
        if(done[a[cen][i].f]) continue;
        if(i!=0) solve2(a[cen][i].f,-1,a[cen][i].s,1-a[cen][i].s);
        solve(a[cen][i].f,-1,a[cen][i].s,1-a[cen][i].s);
    }
    ans2=ans3=0;
    while(!changed.empty()){
        dif[changed.top()] = 0;
        changed.pop();
    }while(!changed2.empty()){
        dif2[changed2.top()] = 0;
        changed2.pop();
    }
    for(pii &i : a[cen]){
        if(!done[i.f]) decomp(i.f);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    char z;
    for (int i =0,x,y; i < n-1; i++){
        cin>>x>>y>>z;
        //x--; y--;
        a[x].pb({y, z == 'r'});
        a[y].pb({x, z=='r'});
    }
    decomp(1);
    cout<<ans;



}
