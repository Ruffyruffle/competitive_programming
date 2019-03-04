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
int n,m,ans,a,b;

vector<int> x;
vector<int> y;
int main(){
    int n,a,b;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        x.pb(a); y.pb(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout<<(2*abs(x[n-1]-x[0])+2*abs(y[n-1]-y[0]))*m;
}
