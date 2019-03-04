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
#define MAXN 101
using namespace std;
int n,m,ans,k;
vector<pii> a[MAXN];
vector<int> b,c;
bool d[101];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i =0,x; i < n; i++){
        cin>>x; b.pb(x);
    }
    for (int i =0,x; i < n; i++){
        cin>>x;c.pb(x);
    }
    for (int i =0,x; i < n; i++){
        a[c[i]].pb({b[i],i+1});
    }
    for(int i = 0,x; i < k; i++){
        cin>>x;
        d[x]=1;
    }
    for(int i = 0; i < MAXN; i++){
        if(a[i].size()==0) continue;
        sort(a[i].begin(),a[i].end());
        if(d[a[i][a[i].size()-1].s]) ans++;
    }
    cout<<k-ans;




}
