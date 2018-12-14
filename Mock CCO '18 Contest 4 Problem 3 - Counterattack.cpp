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
#define MAXN 1000000
using namespace std;
int n,m,d[MAXN],p[MAXN],cou[MAXN];
pii pp[MAXN];
bool in[MAXN];
vector<pair<int,pii>> a[MAXN];
vector<pii> sh;

int sfpa(int cur, int y){
    MEM(d,INF);
    queue<int> f;
    f.push(cur);
    d[cur] = 0;
    while(!f.empty()){
        cur = f.front(); f.pop(); in[cur] = 0;
        for(pair<int,pii> i : a[cur]){
            if(d[i.s.s] > d[cur] + i.s.f){
                d[i.s.s] = d[cur] + i.s.f;
                pp[i.s.s] = {cur, i.f};
                p[i.s.s] = cur;
                if(!in[i.s.s]){
                    f.push(i.s.s);
                    in[i.s.s] = 1;
                }
            }
        }
    }
    return d[y];
}

int spfa2(int cur, int y){
    MEM(d,INF);
    queue<int> f;
    f.push(cur);
    d[cur] = 0;
    while(!f.empty()){
        cur = f.front(); f.pop(); in[cur] = 0;
        for(pair<int,pii> i : a[cur]){
            if(d[i.s.s] > d[cur] + i.s.f){
                d[i.s.s] = d[cur] + i.s.f;
                if(!in[i.s.s]){
                    f.push(i.s.s);
                    in[i.s.s] = 1;
                }
            }
        }
    }
    return d[y];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        a[x].pb({cou[x],{v,y}});
        a[y].pb({cou[y],{v,x}});
        cou[x]++;cou[y]++;
    }
    int s = sfpa(1,n);
    int t = n;
    while(t != 1){
        sh.pb(pp[t]);
        t = p[t];
    }
    int ans = INF;
    vector<int> shv;

    for(pii i : sh){
        int t = a[i.f][i.s].s.f;
        shv.pb(t);
        a[i.f][i.s].s.f = INF;
        ans = min(ans, spfa2(1,n));
        a[i.f][i.s].s.f = t;
    }

    sort(shv.begin(), shv.end());
    cout<<min(ans, s + 2*shv[0])<<endl;
}
