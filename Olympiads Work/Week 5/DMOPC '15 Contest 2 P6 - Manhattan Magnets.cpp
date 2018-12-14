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
#define MAXN 10000
using namespace std;
int n,m,ans,tint[MAXN];
struct line{
    int x,y1,y2,v;
};
struct met{
    int x,y;
};
vector<line> a;
vector<met> mt;
vector<met> mg;

bool cmp(line a, line b){return (b.x == a.x ? b.v < a.v : b.x > a.x);}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m;
    for(int i = 0,x,y; i < m; i++){
        cin>>x>>y;
        mg.pb({x-y,x+y});
    }
    cin>>n;
    for(int i = 0,x,y; i < n; i++){
        cin>>x>>y;
        mt.pb({x-y,x+y});
    }

    for(met i : mt){
        int ans = INF;
        for(met j : mg){
            ans = min(ans, max(abs(i.x - j.x), abs(i.y - j.y)));
        }
        ans = max(0, ans-1);
        a.pb({i.x - ans, i.y + ans, max(i.y - ans,0), 1});
        a.pb({i.x + ans, i.y + ans, max(i.y - ans,0), -1});
    }

    sort(a.begin(), a.end(), cmp);
    ans = -1;
    for(line i : a){
        for(int j = 0; j < MAXN; j++){
            ans = max(ans,tint[j]);
        }
        for(int j = i.y2; j <= i.y1; j++){
            tint[j] += i.v;
        }
    }
    cout<<ans;
}
