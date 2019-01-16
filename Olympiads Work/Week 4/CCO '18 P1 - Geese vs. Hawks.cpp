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
vector<int> a,b;
int dp[MAXN][MAXN];
string sa,sb;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    a.pb(0);b.pb(0);
    cin>>n>>sa;
    for (int i =0,x; i < n; i++){
        cin>>x; a.pb(x);
    }
    cin>>sb;
    for(int i = 0,x; i < n; i++){
        cin>>x; b.pb(x);
    }
    sa='a'+sa;
    sb='a'+sb;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            dp[i][j] = ((sa[i] == 'W' && sb[j] == 'L' && a[i] > b[j]) || (sa[i] == 'L' && sb[j] == 'W' && a[i] < b[j]) ?max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + a[i]+b[j])):max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout<<dp[n][n];



}
