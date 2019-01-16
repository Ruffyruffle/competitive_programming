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
#define MAXN 5001
using namespace std;
int n,m;
int dp[501][MAXN];
int fans[MAXN];
vector<int> a; vector<int> ans,ans2;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    a.pb(0);
    cin>>m>>n;
    for (int i =1,x; i <= n; i++){
        cin>>x;
        a.pb(x);
        for(int j = 1; j <= m; j++){
            if(x>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-x] + x, dp[i-1][j]);
        }
    }
    int f = n, s=m;
    while(f!=0){
        if(dp[f][s] > dp[f-1][s]){
            ans.pb(f);
            s-=a[f];
            f--;
        }
        else{
            ans2.pb(f);
            f--;
        }
    }
    int tot = 0;
    for(int i : ans){
        fans[i] = tot;
        tot+=a[i];
    } tot=0;
    for(int i : ans2){
        fans[i] = tot;
        tot+=a[i];
    }
    for(int i = 1; i <= n; i++){
        cout<<fans[i]<<" ";
    }

}
