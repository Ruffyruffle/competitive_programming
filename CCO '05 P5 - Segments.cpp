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
int n,m,ans,k;

pii a[MAXN];
int dp[MAXN][2];
int last[MAXN][2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;

    for(int i = 1,x,y; i <= n; i++){
        cin>>x>>y;
        a[i] = {x,y};
    }
    MEM(dp,INF);
    dp[0][0] = dp[0][1] = 0;
    last[0][0] = last[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j=0; j < 2; j++){
                if(dp[i][0] > a[i].s - a[i].f + abs(last[i-1][j] - a[i].s) + dp[i-1][j]){
                    dp[i][0] = a[i].s - a[i].f + abs(last[i-1][j] - a[i].s) + dp[i-1][j];
                    last[i][0] = a[i].f;
                }
                //cout<<a[i].s-a[i].f<<" "<<abs(last[i-1][j] - a[i].f)<<endl;
                if(dp[i][1] > a[i].s - a[i].f + abs(last[i-1][j] - a[i].f) + dp[i-1][j]){
                    dp[i][1] = a[i].s - a[i].f + abs(last[i-1][j] - a[i].f) + dp[i-1][j];
                    last[i][1] = a[i].s;
                }
        }
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;;
    }
    cout<<min(dp[n][0] + abs(last[n][0] - n),dp[n][1] + abs(last[n][1] - n))  + n-1;







}
