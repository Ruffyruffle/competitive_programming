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
#define MAXN 1001
using namespace std;
int n,m,ans,d,l,r;
int dp[MAXN][MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>d>>l>>r;
    string s,ss; cin>>s>>ss;
    for(int i = 1; i <= max(s.length(),ss.length()); i++){
        dp[0][i] = l*i;
        dp[i][0] = d*i;
    }
    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= ss.length(); j++){
            if(s[i-1]==ss[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i][j-1] + l, dp[i-1][j] + d), dp[i-1][j-1] + r);
        }
    }
    cout<<dp[s.length()][ss.length()];
}
