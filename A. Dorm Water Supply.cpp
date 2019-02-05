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
int n,m; vector<piii> ans;
bool start[MAXN];
vector<pii> a[MAXN];
void dfs(int cur,int mn,int first){
    if(a[cur].size() == 0){
        ans.pb({mn, {first, cur}});
    }
    else{
        for(pii i : a[cur]){
            dfs(i.f,min(i.s,mn),first);
        }
    }
}
bool cmp(piii a, piii b){return a.s.f < b.s.f;}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        a[x].pb({y,v});
        start[y] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!start[i] && a[i].size() != 0){
            dfs(i,INF,i);
        }
    }
    sort(ans.begin(), ans.end(),cmp);
    cout<<ans.size()<<endl;
    for(piii i : ans){
        cout<<i.s.f<<" "<<i.s.s<<" "<<i.f<<endl;
    }



}
