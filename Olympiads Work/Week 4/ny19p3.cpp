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
#define MAXN 1000002
using namespace std;
int n,m,ans;
int par[MAXN];
int d[MAXN];
int last[MAXN];
//bool in[MAXN];
vector<pii> a[MAXN];

int main(){
    MEM(d,INF);
    MEM(last,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int s,e;
    for (int i =0,x,y; i < m; i++){
        cin>>x>>y;
        a[x].pb({y,i});
        if(i==0){
            s = x;
        }
        if(i == m-1){
            e = y;
        }
    }
    queue<int> q;
    q.push(s);
    d[s] = 0;
    last[s] = -1;
    //last[s] = 0;
    int cur;

    //in[s] = 1;
    while(!q.empty()){
        cur = q.front(); q.pop();
        //in[cur] = 0;
        for(pii i : a[cur]){
            //if(cur == i.f) continue;
            if(d[i.f] == INF && i.s > last[cur]){
                d[i.f] = d[cur] + 1;
                par[i.f] = cur;
                last[i.f] = i.s;
                //if(!in[i.f]){
                    //in[i.f] = 1;
                q.push(i.f);
                //}
            }
        }
    }
    cout<<d[e]<<endl;
    stack<pii> ans;
    cur = e;
    par[s] = s;
    while(cur != s){
        ans.push({par[cur], cur});
        cur = par[cur];
//        if(cur == par[cur])
//            break;
    }
    while(!ans.empty()){
        cout<<ans.top().f<<" "<<ans.top().s<<endl;
        ans.pop();
    }





}
