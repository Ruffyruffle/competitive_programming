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
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 100005
using namespace std;
ll n,m,ans,a[MAXN];
bool fuck[MAXN];
vector<int> c;
vector<int> f[MAXN];

void si(int n)
{
    for (int p=2;  p*p<n; p++)
    {
        if (!fuck[p])
        {
            for (int i=p*p;i<=n; i += p)
                fuck[i]=1;
        }
    }

    for (int p=2; p<=n; p++)
       if (!fuck[p]) c.pb(p);
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x,y,ans=0,k,v;
    cin>>n>>m;
    si(MAXN);
    MEM(fuck, 0);
    for(int i = 0; i < m; i++){
        cin>>x;
        if(x == 1){
            cin>>k>>v;
            a[k]+=v;
            if(!fuck[k]){
                for(int j = k; j < MAXN; j+=k){
                    f[j].pb(k);
                }
                fuck[k] = 1;
            }
        }
        else{
            cin>>y;
            ans = 0;
            for(int j : f[y]){
                ans+=a[j];
            }
            cout<<ans<<endl;
        }
    }
}
