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
typedef std::pair<ll, ll> pii;
typedef std::pair<ll, pii> piii;

const ll INF = 0x3f3f3f3f;
#define MAXN 300002
using namespace std;
ll n,m,ans,k;
vector<ll> a[MAXN];
vector<ll> b;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (ll i =0,x,y; i < n; i++){
        cin>>x>>y; a[x].pb(y);
    }
    for(ll i = 1; i <= k; i++){
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
    }
    int e =0;
    for(ll i = 1; i <= k; i++){
        if(a[i].size() != 0){
            ans+=a[i][0]; e++;
        }

    }
    for(ll i = 1; i <= k; i++){
        if(a[i].size() == 1) continue;
        for(ll j = 1; j < a[i].size(); j++){
            b.pb(a[i][j]);
        }
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for(ll i = 0; i < m-e; i++){
        //if(i > b.size()-1) break;
        ans+=b[i];
    }
    //cout<<m-k<<endl;
    cout<<ans;

}
