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
#define MAXN 200005
using namespace std;
int n,m,ans,ans2;
int a[MAXN];
int b[MAXN];
//unordered_map<long double,int> f;
map<pii,int> f;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0; i < n; i++){
        cin>>a[i];
    }
    int x;
    for (int i =0; i < n; i++){
        cin>>x;
        if(a[i]==0 && x == 0) ans2++;
        if(a[i]==0) continue;
        int t = __gcd(a[i],x);
        a[i]/=t;
        x/=t;
        f[{x,a[i]}]++;
    }
    for(auto i : f){
        ans = max(ans, i.s);
    }
    cout<<ans+ans2;



}
