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
#define MAXN 1001
using namespace std;
int n,k;ll ans=1;
int dp[MAXN][MAXN];

vector<int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    a.pb(0);
    for (int i =0,x; i < n; i++){
        cin>>x;

        a.pb(x);
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = i;
    }
    sort(a.begin(), a.end());
    int last = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 2; j <= n; j++){
            if(a[i] != a[i-1]) last = i-1;
            dp[i][j] = (dp[i-1][j] + a[i]*a[last])%998244353;
        }
    }
   for(int i = 0; i < n; i++){
        cout<<dp[n][i]<<" ";
   }

}
