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
#define MAXN 5001
using namespace std;
ll n,m,a,v,p; ll ans;
ll dp[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(n--){
        cin>>a>>v>>p;
        for(ll i = 1; i <=a && v*i<MAXN; i<<=1){
            ll val = p*i, w = v*i;
            for(int j = 5000; j >= w; j--){
                dp[j] = max(dp[j], dp[j-w] + val);
            }
        }
    }
    ans = -INF;
    for(int i=0,x,y; i<m; i++){
        cin>>x>>y;
        ans = max(ans, dp[x] - y);
    }
    cout<<ans;



}
