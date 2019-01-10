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
#define MAXN 20001
using namespace std;
int n,m,k,q,ans;
vector<pii> a[MAXN];
int d[MAXN];
bool hub[MAXN],done[MAXN];

void dik(int j, int cur){
    MEM(d[j], INF);
    queue<int> q;
    q.pb(cur);
    d[j][cur] = 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(pii i : a[cur]){
            if(i.s + d[j][cur] < d[j][i.f]){
                d[j][i.f] = i.s + d[j][cur];
                q.pb(i.f);
            }
        }
    }

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    for(int i = 0,x,y,v; i < m; i++){
        cin>>x>>y>>v;
        a[x].pb({y,v});
    }
    unordered_map<int,int> toi,tox;
    for (int i =0,x; i < k; i++){
        cin>>x;
        hub[x] = 1;
        toi[x] = i;
        tox[i] = x;
    }
    for (int i =0,a,b; i < q; i++){
        cin>>a>>b;
        if(!hub[a])
            swap(a,b);
        if(!done[toi[a]]){
            dik(toi[a], a);
        }
    }
}
