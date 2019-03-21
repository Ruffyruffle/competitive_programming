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
int n,m,ans,k,q,t;
//int dif[MAXN][MAXN];;
int area[MAXN][MAXN];
int x,y,x2,y2;
vector<pii> a;
struct line{
    int x, y1, y2, t;
};
vector<line> b;
bool cmp(line a, line b){return b.x > a.x;}
int v[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q>>t;
    for (int i =0,x,y; i < k; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    for(int i = 0; i < q; i++){
        cin>>x>>y>>x2>>y2;
        b.pb({x,y,y2,1});
        b.pb({x2+1,y,y2,-1});
    }
    sort(b.begin(),b.end(),cmp);
    int cur = 0;
    for(int i =1; i <= n; i++){
        //for(int j = 1; j <= m; j++){
        while(b.size()>cur && b[cur].x == i){
            for(int k = b[cur].y1; k <= b[cur].y2; k++){
                v[k]+=b[cur].t;
            }
            cur++;
        }
        for(int j = 1; j <= m; j++){
            area[i][j] = v[j];
            //cout<<area[i][j]<<" ";
        }
   // }
        //cout<<endl;
    }
    for(pii c : a){
        int mx = -1;
        for(int i = max(1, c.f-t); i <= min(MAXN-1, c.f + t); i++){
            mx = max(mx, area[i][c.s]);
        }
        for(int i = max(1, c.s-t); i <= min(MAXN-1, c.s + t); i++){
            mx = max(mx, area[c.f][i]);
        }
        ans+=mx;
    }
    cout<<ans;



}
