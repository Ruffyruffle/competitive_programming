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
int n,m,ans;
int dp[MAXN][MAXN];
int mod = 1e9+7;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    char c;

    for (int i =0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin>>c;
            if(c=='#')
                dp[i][j] = -1;
        }
    }
    for(int i = 0; i < MAXN; i++){
        if(dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }
    for(int i = 0; i < MAXN; i++){
        if(dp[0][i] == -1)
            break;
        dp[0][i] = 1;
    }
    for(int i = 1; i <n; i++){
        for(int j = 1; j <m; j++){
            if(dp[i][j] == -1) continue;
            if(dp[i-1][j] != -1 && dp[i][j-1] != -1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if(dp[i][j-1] != -1)
                dp[i][j] = dp[i][j-1];
            else if(dp[i-1][j] != -1)
                dp[i][j] = dp[i-1][j];
            dp[i][j]%=mod;
            //cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n-1][m-1];
}
