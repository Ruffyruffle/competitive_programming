#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 10001
using namespace std;
int n,m,k;
vector<pair<int,pii>> a;
vector<pii> b[MAXN];
int d[MAXN];

vector<int> par, rk;
void init(){
    par.resize(n+1); rk.resize(n+1);
    for(int i =0; i < n; i++){
        par[i] = i;
        rk[i] = 0;
    }
}
int fnd(int v){
    if(v==par[v]) return v;
    return par[v] = fnd(par[v]);
}

void onion(int a, int b){
    a = fnd(a); b=fnd(b);
    if(rk[b] > rk[a]){
        swap(a,b);
    }
    par[b] = a;
    if(rk[a] == rk[b]) rk[a]++;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);scan(m); scan(k);
    init();
    for (int i =0,x,y,v; i < m; i++){
        scan(x);scan(y);scan(v);
        a.pb({v,{x,y}});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(pair<int,pii> i : a){
        if(fnd(i.second.first) != fnd(i.second.second)){
            onion(i.second.first, i.second.second);
            //cout<<i.second.first<<" "<<i.second.second<<" "<<i.first<<endl;
            b[i.second.first].pb({i.first,i.second.second});
            b[i.second.second].pb({i.first,i.second.first});
        }
    }

    int cur = 1, mx = INF;
    queue<pii> f;
    f.push({1,INF});
    while(!f.empty()){
        cur = f.front().first, mx = f.front().second;
        //cout<<cur;
        f.pop();
        for(pii i : b[cur]){
            if(d[i.second] == 0){
                d[i.second] = min(i.first, mx);
                f.push({i.second,d[i.second]});
            }
        }
    }
    int ans = INF;

    vector<int> des;
    for(int i = 0,x; i < k; i++){
        scan(x);
        des.pb(x);
    }

    for(int i = 0; i < k; i++){
        ans = min(ans, d[des[i]]);
    }

    cout<<ans;
}
