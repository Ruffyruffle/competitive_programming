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
int n,m;
bool done[MAXN];
ll ans;
ll b[MAXN];
ll c[MAXN];
vector<pair<pii, bool>> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n; i++){
        //cin>>a[i].f>>a[i].s;
        cin>>b[i]>>c[i];
        a.pb({{b[i],i},0});
        a.pb({{c[i],i},1});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int l=-0,r=n-1;
    for(auto i : a){
        if(done[i.f.s]) continue;
        cout<<i.f.s<<endl;
        done[i.f.s]=1;
        if(i.s){
            ans += i.f.f*(n-r-1) + b[i.f.s] * r;r--;
        }
        else ans +=c[i.f.s]*(n-l-1) + i.f.f * l++;
        cout<<ans<<endl;
    }
    cout<<ans;




}
