#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 2003
ll n, dp[MAXN][MAXN][2], h[MAXN][MAXN][2], psa[MAXN], ans = 0; pii a[MAXN];

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].f>>a[i].s;
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <=n; i++){
        psa[i] = psa[i-1] + a[i].s;
        if(a[i].f == 0)
            dp[i][i][0] = dp[i][i][1] = a[i].s;
    }
    for(int le = 1; le < n; le++){
        for(int l = 1; l+le <= n; l++){
            int r = le+l;
            if(dp[l+1][r][0] >= a[l+1].f -a[l].f)
                dp[l][r][0]=max(dp[l][r][0], dp[l+1][r][0] + a[l].s - (a[l+1].f -a[l].f));
            if(dp[l+1][r][1] >= a[r].f - a[l].f)
                dp[l][r][0]=max(dp[l][r][0], dp[l+1][r][1] + a[l].s - (a[r].f -a[l].f));
            if(dp[l][r-1][1] >= a[r].f - a[r-1].f)
                dp[l][r][1] = max(dp[l][r][1], dp[l][r-1][1] + a[r].s - (a[r].f - a[r-1].f));
            if(dp[l][r-1][0] >= a[r].f - a[l].f)
                dp[l][r][1] = max(dp[l][r][1], dp[l][r-1][0] + a[r].s - (a[r].f - a[l].f));

//            if(dp[l][r][0] > 0 || dp[l][r][1] > 0)
//                ans = max(ans, psa[r] - psa[l-1]);
        }
    }
    for(int l=1; l<=n; l++)
        for(int r=l; r<=n; r++)
            if(dp[l][r][0] > 0 || dp[l][r][1] > 0)
                ans = max(ans, psa[r]-psa[l-1]);
    cout<<ans;
}
