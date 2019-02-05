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
ll n,m,k; ld ans;
ll a[MAXN],psa[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0); cout<<fixed<<setprecision(6);
    cin>>n>>k>>m;
    for (int i =1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1; i<=n; i++) psa[i] = psa[i-1] + a[i];
    for(int i = 0; i <= min(m,n-1); i++){
        ans = max(ans, (psa[n] - psa[i] + min(m-i, (n-i)*k))/ (ld)(n-i));
    }
    cout<<ans;



}
