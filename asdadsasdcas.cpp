#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    vector<int> l, r;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        l.pb(x); r.pb(y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans+=max(l[i], r[i]);
    }
    cout<<ans+n;




}
