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
#define MAXN 100002
using namespace std;
ll n,k,ans,a,b,x;
vector<ll> aa;
unordered_map<ll, int> o;
ll bit[MAXN];
void add(int i, int v){
    while(i<= MAXN){
        bit[i]+=v;
        i+=(-i&i);
    }
}
ll sum(int i){
    ll ans = 0;
    while(i>0){
        ans+=bit[i];
        i-= (i&-i);
    }
    return ans;
}

ll solve(ll l, ll r, ll n){
    if(l>r) return 0ll;
    ll t = sum(o[*upper_bound(aa.begin(), aa.end(), r)]) -
       sum(o[*lower_bound(aa.begin(), aa.end(), l)]);
    //cout<<t<<endl;
    //cout<<l<<" "<<r<<" "<<t<<endl;
    if(t == 0)
    {
           return a;
    }
    ll cost = b*t*pow(2,n);
    if(l==r) return cost;
    ll mid = (l+r)>>1;
    return min(solve(l, mid, n-1) + solve(mid+1,r, n-1), cost);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>a>>b;

    for (int i =0; i < k; i++){
        cin>>x;
        aa.pb(x);
    }
    sort(aa.begin(), aa.end());
    UNI(aa);
    for(int i = 1; i <= aa.size(); i++){
        o[aa[i]] = i;
        add(i, 1);
    }
    cout<<solve(1,pow(2,n),n);
}
