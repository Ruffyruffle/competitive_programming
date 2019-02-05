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
typedef std::pair<double, double> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,m; double ans;
vector<pii> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0); cout<<fixed<<setprecision(2);
    cin>>n; int j = n-1;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y; a.pb({x,y});
    }
    for(int i = 0; i < n; i++){
        ans+=(a[j].f + a[i].f)*(a[j].s-a[i].s);
        j=i;
    }
    cout<<abs(ans/2.0);



}
