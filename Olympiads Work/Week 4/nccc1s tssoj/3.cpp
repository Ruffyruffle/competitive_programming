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
#define MAXN 2001
using namespace std;
int n,m,ans;
int d[MAXN];
bool k[MAXN];
bool l[MAXN];
vector<int> a[MAXN];
int num[MAXN];
int p[MAXN];

void dfs(int cur, int last, int dis){
    int c = 0;
    d[cur] = dis;
    for(int i : a[cur]){
        if(i==last || k[i]) continue;
        c++;
        dfs(i,cur,dis+1);
    }
    num[cur] = c;

    if(c == 0)
        l[cur] = 1;
    p[cur] = num[last];
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    int fx=-1, root = 1;
    MEM(d,INF);
    queue<int> q; q.push(1); int cur; d[1] = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int i : a[cur]){
            if(d[i] == INF){
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        if(root < d[i]){
            root = d[i];
            root = i;
        }
    }
    int fuck  = INF;
    while(fuck > m){
        int best = INF, bi;
        dfs(root,-1,0);
        fuck = -1;
        for(int i = 1; i <= n; i++){
            if(k[i]) continue;
            if(d[i] > fuck){
                fuck = d[i];
            }
        }
        for(int i = 1; i <= n; i++){
            if(k[i]) continue;
            if(d[i] == fuck){
                if(best > p[i]){
                    best = p[i];
                    bi = i;
                }
            }
        }

        //if(num[root] == 1){
            int curm=0, tt=-1;
            for(int i : a[root]){
                if(k[i]) continue;
                tt = i;
            }
            curm = num[tt];
            if(curm < best && num[root] == 1){
                k[root] = 1;
                root = tt;
                ans+=curm-1;
            }
            else k[bi] = 1;
        //}





        ans++;
    }
    cout<<ans-1;

//FUCK
}
