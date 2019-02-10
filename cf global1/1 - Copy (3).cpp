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
#define MAXN 1000000
using namespace std;
ll n,m,ans;
ll dp[26];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<endl;
    ll last = 0;

    dp[0] = 1;
    for(ll i = 1; i < 26; i++){
        dp[i] = dp[i-1]<<1|1;
    }
    for (ll i =0,x; i < n; i++){
        cin>>x;
        bool s = 0; ll tt = 0;

        for(ll j = 25; j >=1; j--){
            if(x%dp[j] == 0){
                s = 1;
                tt= x/dp[j];
            }
            if(s) break;
        }
        ll t = floor(log2(x));
        cout<<max(dp[t],tt)<<endl;
    }



}
