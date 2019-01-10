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
int n,m,ans=INF,d[MAXN];
vector<int> a[MAXN];
bool root[MAXN];

void dfs(int cur, int last){
    for(int i : a[cur]){
        if(i==last) continue;
        if(d[i]!=0){
            ans = min(d[cur]-d[i]+1, ans);
        }
        else{d[i] = d[cur] + 1;
        dfs(i,cur);}
    }

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =1,x; i <= n; i++){
        cin>>x;
        a[i].pb(x);
        root[x] = 1;
    }
    vector<int> rt;
    rt.pb(1);
    for(int i = 1; i <=n;i++){
        if(!root[i])
            rt.pb(i);
    }
    for(int i : rt) {
        MEM(d,0);
        dfs(i,-1);
    }

    cout<<ans;
}
