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
#define MAXN 1000000
using namespace std;
int n,m,ans,k,t;
int dp[MAXN];
int temp[MAXN];
vector<pii> a[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t>>n;
    for(int i = 0,x,y,z; i < n; i++){
        cin>>x>>y>>z;
        a[z].pb({x,y});
    }
    cin>>m;
    for(int i =1; i <= t; i++){
        MEM(temp,0);
        for(pii z : a[i]){
            for(int j = z.f; j <= m; j++){
                temp[j] = max(temp[j], dp[j-z.f] + z.s);
            }
        }
        for(int j=1;j<=m;j++)dp[j] = max(dp[j-1], temp[j]);
    }
    cout<<(dp[m] == 0?-1:dp[m]);








}
