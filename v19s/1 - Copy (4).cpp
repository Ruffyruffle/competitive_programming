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
#define MAXN 100001
using namespace std;
int n,m,ans,k;
bool used[MAXN];
vector<pii> a,u,b;
int la[MAXN];

bool cmp2(ll a, pair<ll, ll> b){
    return (a <= b.s);
}
int solve(int l, int r){
    int dp[b.size()+1];
    MEM(dp,0);
    for(int i = 0; i < b.size(); i++){
        if(l > b[i].f || b[i].s > r){
            dp[i+1] = dp[i];
            continue;
        }
        int last = upper_bound(b.begin(), b.end(), b[i].f, cmp2) - b.begin();
        dp[i+1] = max(dp[i], dp[last] + 1);
    }
    //cout<<l<<" "<<r<<" "<<dp[b.size()]<<endl;
    return dp[b.size()];
}
bool cmp(pair<ll, ll>  a, pair<ll, ll>  b){
    return (b.s > a.s);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    sort(a.begin(),a.end());
    int last = 0, ans2=0;
    for(int i = 0; i < n; i++){
        if(a[i].f > last){
            ans2++;
            u.pb(a[i]);
            la[i] = last;
            last = a[i].s;
        }
        else{
            b.pb(a[i]);
        }
    }
    sort(b.begin(),b.end(),cmp);
//    for(pii i : u){
//        ans = max(ans, solve(i.f,i.s));
//    }
    if(u.size()>1)ans = max(ans, solve(0, u[1].f-1));
    for(int i = 1; i < n-1; i++){
        ans = max(ans, solve(u[i-1].s+1, u[i+1].f-1));
    }
    if(u.size()>1)ans = max(ans, solve(u[u.size()-2].s+1, 100000000));
    //cout<<ans2<<endl;
    cout<<max(ans2,ans2-1+ans);




}
