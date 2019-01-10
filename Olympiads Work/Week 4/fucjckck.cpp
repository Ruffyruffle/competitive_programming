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
vector<int> a;
int par[MAXN];
int d[MAXN];
int fr[MAXN];

int main(){
    MEM(d,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int x,y,s;
    for (int i =0; i < m; i++){
        cin>>x>>y;
        if(i == 0){
            d[x] = 0;
            par[x] = -1; s = x;
        }
        if(d[y] > d[x] + 1){
            d[y] = d[x] + 1;
            par[y] = x;
        }
    }
    //cout<<d[y]<<endl;
    int cur = y;
    int c = 0;
    while(cur != s){
        fr[par[cur]] = cur;
        //assert(par[cur] != cur);
        //assert(cur > 0);
        cur = par[cur];
        c++;
    }
    cout<<c<<endl;
    cur = s;
    while(cur != y){
        cout<<cur<<" "<<fr[cur]<<endl;
        cur = fr[cur];
    }
}
