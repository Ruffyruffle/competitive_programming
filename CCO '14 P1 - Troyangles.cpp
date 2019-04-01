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
#define MAXN 2001
using namespace std;
int n,m,ans,k;
char a[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    MEM(dp,0);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n; string s;
    for(int i = 1; i <= n; i++){
        cin>>s;
        for(int j = 1; j <= n; j++){
            a[i][j] = s[j-1];
            if(s[j-1] == '#') dp[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = n; j >=1; j--){
            if(a[i][j] == '#'){
                dp[i][j] += min(min(dp[i-1][j+1],dp[i][j+1]), dp[i][j+2]);
            }
            //cout<<dp[i][j]<<" ";
            ans+=dp[i][j];
        }
        //cout<<endl;
    }
    cout<<ans;







}
