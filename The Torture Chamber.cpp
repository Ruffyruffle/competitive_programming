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
#define MAXN 20000002
using namespace std;
ll n,m,ans;
bitset<MAXN> s;
vector<ll> ca;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    s.set();
    for (int i =2; i < ceil(sqrt(m)); i++){
        if(!s[i]) continue;
        ca.pb(i);
        for(int j = i; j < ceil(sqrt(m)); j+=i){
            s[j] = 0;
        }
    }s.set();
    for(ll i : ca){
        ans = m/i*i;
        for(ll j = ans; j>= n; j-= i){
            if(i==j) break;
            if(s[m-j]) s[m-j] = 0;
        }
    }
    ans = (n<3?-1:0);
    for(int i = 1; i <=m-n; i++){
        if(s[i]) ans++;
    }
    cout<<ans;
}
