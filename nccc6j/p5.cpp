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

ll fac(int n){
    ll t = 1;
    for(ll i = n; i>=1; i--){
        t*=i; t%=998244353;
    }
    return t;
}

ll choose(int n, int r){
    return fac(n)/(fac(r)* fac(n-r));
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    a.pb(0);
    for (int i =0,x; i < n; i++){
        cin>>x;
//        fr[x]++; //a.pb(x);
//        if(fr[x] == 1) b
        a.pb(x);
    }
//    ans=fac(b.size())/(fac(k)*fac(b.size()-k));
//    for(int i = 0; i < MAXN; i++){
//        if(fr[i] == 0) continue;
//        ans*=fr[i]);
//        ans%=998244353;
//    }
//
////    ans%=998244353;
//    ll ans2= 1;
//    if(k==1){
//        cout<<n<<endl; return 0;
//    }
////    for(int i = 0; i < b.size(); i++){
////        ans2*=fac(fr[b[i]]);
////    }
//    //cout<<choose(n,k)/ans2<<endl;
//    if(k==2){
//        ans = 0;
//        for(int i = 0; i < b.size(); i++){
//            for(int j = i+1; j < b.size(); j++){
//                ans+=fr[b[i]] * fr[b[j]];
//                //cout<<i<<" "<<j<<endl;
//                ans%=998244353;
//            }
//        }
//        cout<<ans<<endl; return 0;
//    }
//    ans = choose(b.size(), k);
//    or(int i = 0; i < b.size(); i++){

    //}
    for(int i = 1; i <= n; i++){
        dp[i][1] = i;
    }
    sort(a.begin(), a.end());
    int last = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 2; j <= k; j++){
            if(a[i] != a[i-1]) last = i-1;
            dp[i][j] = (dp[i-1][j] + dp[last][j-1])%998244353;
        }
    }
    cout<<dp[n][k];




}
