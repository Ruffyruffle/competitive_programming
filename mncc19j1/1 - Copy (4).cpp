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
typedef std::pair<ll, ll> pii;
typedef std::pair<ll, pii> piii;

const ll INF = 0x3f3f3f3f;
#define MAXN 30
using namespace std;
ll n,m,ans;
ll dp[MAXN][MAXN];
ll a[MAXN];
    ll x,y;
ll solve(ll cur, ll pos){
    //cout<<cur<<" "<<pos<<endl;
    if(pos == n-1) return 1;
    ll ret = 0;
    //cout<<y-(n-pos)+1<<endl;
    for(ll i = cur+1; i <= y-(n-pos)+1; i++){
        ret+=solve(i,pos+1);
    }
    return ret;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>x>>y;
    for(int i = 0; i <=y-x; i++){
        dp[0][i] = 1;
    }
    for(ll i = 1 ; i < y-x; i++){
        for(ll j = 0; j <=min(i,n-2); j++){
            if(j==i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
//    ll ans = 0;
//    if(x>=y) cout<<0;
//    else cout<<solve(1, x);
    cout<<dp[y-x-1][n-2];



}
