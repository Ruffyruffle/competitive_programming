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
typedef std::pair<pii, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 2002
using namespace std;
int n,m,ans;
piii a[MAXN]; //time, end,  val
int dp[MAXN][MAXN];

bool cmp2(piii a,piii b){return b.s.f > a.s.f;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =1,x,y,v; i <= n; i++){
        cin>>x>>y>>v;
        a[i] = {{x,i},{y,v}};
    }
    sort(a+1, a+1+n,cmp2);
//    for(int i = 1; i < n; i++){
//        int last = upper_bound(a+1,a+n+1,a[i].s.f,cmp)-a-1;
//        dp[i] = max(dp[i-1], dp[last] + a[i].s.s);
//    }
//    cout<<dp[n];
    for(int i = 1; i <= n; i++){
        for(int j = a[i].f.f; j < MAXN; j++){
            if(a[i].s.f > j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].f.f] + a[i].s.s);
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        for(int j = 0; j < a[i].f.f; j++){
            dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> ans;
    int i = n, j = MAXN-1;
    while(i>0 && j>0){
        if(dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1]){
            j-=a[i].f.f; ans.pb(a[i].f.s); i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
    }
    cout<<dp[n][MAXN-1]<<endl<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(int i : ans){cout<<i<<" ";}




}
