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
#define MAXN 1000000
using namespace std;
int n,m,ans,a[MAXN];
bool done[MAXN];
vector<ll> c;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1,x; i <= n; i++){
        cin>>a[i];
    }
    for (int i =1; i <= n; i++){
        int cur = i, len = 0;
        while(!done[cur]){len++; done[cur] = 1; cur = a[cur]; }
        if(len!=0) c.pb(len);
    }
    ll ans = 0;
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    if(c.size() == 1){cout<<c[0]*c[0]; return 0;}
    c.pb(c[0] + c[1]);
    for(int i = 2; i < c.size(); i++){
        ans+=c[i]*c[i];
        //cout<<c[i]<<endl;
    }
    cout<<ans;
}
