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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 401
using namespace std;
ll n,m,ans;
ll dp[MAXN];
vector<ll> a; bool b[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =1,x; i <= n; i++){
        cin>>x;
        a.pb(x);
    }
    while(a.size()!=1){
        ll mn = INF, mi = 0;
        for(int i = 0; i < a.size()-1;i++){
            if(mn > a[i] + a[i+1]){
                mn = a[i] + a[i+1];
                mi = i;
            }
        }
        a[mi] = a[mi] + a[mi+1];
        a.erase(a.begin()+mi+1);
        ans+=a[mi];
    }
    cout<<ans;



}
