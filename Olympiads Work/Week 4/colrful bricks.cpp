//#include "factories.h"
#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef std::pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 2001
int n,m,k;
ll dp[MAXN][MAXN];
using namespace std;
int main(){
    cin>>n>>m>>k;
    dp[0][0] = m;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j <= k; j++){
            dp[i+1][j] += dp[i][j]% 998244353;
            dp[i+1][j+1] += (dp[i][j]*(m-1))% 998244353;
        }
    }
    cout<<dp[n-1][k] % 998244353;
}
