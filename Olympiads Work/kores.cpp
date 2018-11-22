#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back

typedef long long ll;
typedef std::pair<ll, ll> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,m;
vector<pii> co;
vector<pii> bu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        co.pb({x,y});
    }
    cin>>m;
    for(int i = 0,x,y; i < m; i++){
        cin>>x>>y;
        bu.pb({x,y});
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll mn = INF;
        for(int j = 0; j < m; j++){
            mn = min(mn, abs(co[i].first - bu[j].first) + abs(co[i].second - bu[j].second));
        }
        ans+=mn;
    }
    cout<<ans;
}
