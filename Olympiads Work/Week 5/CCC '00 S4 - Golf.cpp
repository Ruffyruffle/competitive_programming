#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,k;
int dp[5281];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    MEM(dp, INF);
    scan(k); scan(n);
    vector<int> c;
    for (int i =0,x; i < n; i++){
        scan(x);
        c.pb(x);
    }
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i-c[j] >= 0)
                dp[i] = min(dp[i],dp[i-c[j]] + 1);
        }
    }
    if(dp[k] == INF) cout<< "Roberta acknowledges defeat.";
    else cout<< "Roberta wins in "<<dp[k]<<" strokes.";
}
