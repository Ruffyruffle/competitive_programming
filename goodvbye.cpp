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
#define MAXN 1000000
using namespace std;
int n,m,ans;
string s;
vector<ll> a,d;

ll solve(ll k){
    int t =1;
    t =(t+k);
    int f = (n-1) / k;
    return (f) * (1 + (f*k));
}

void pre(int n){
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i)
                d.pb(i);
            else{
                d.pb(i); d.pb(n/i);
            }
        }
    }
}
int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin>>n;
    pre(n);
    for(int i = 1; i <= d.size(); i++){
        a.pb(solve(d[i]) );
    }
    a.pb(solve(1));
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(), a.end()),a.end());
    for(ll i :a){
        cout<<i<<" ";
    }
}
