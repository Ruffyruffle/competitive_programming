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
#define MAXN 3001
using namespace std;
int n,m,ans;
double dp[MAXN][MAXN];
vector<double> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    double x;
    for (int i =0; i < n; i++){
        cin>>x;
        a.pb(x);
    }
    dp[1][1] = a[0];
    dp[1][0] = 1-a[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i+1][j] += dp[i][j] * (1-a[i]);
            dp[i+1][j+1] += dp[i][j] * a[i];
            //dp[i+1][j] += dp[i][j] * (1-a[0]);
        }
    }
    double ans = 0;
    for(int i = n/2 + 1; i <= n; i++){
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(10);
    cout<<ans;



}
