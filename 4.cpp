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
#define MAXN 10000010
using namespace std;
int n;ll ans;char m;
bool d[MAXN];
vector<int> a;
void pre(){
    for(int i = 2; i*i<=n; i++){
        if(d[i]) continue;
        for(int j = i*i; j <= n; j+=i){
            d[j] = 1;
        }
    }
    for(int i=2;i<=n;i++){
        if(!d[i]) a.pb(i);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    pre();
    for(int i : a){
        string s = to_string(i);
        if(s.find(m)!=string::npos){
            ans+=i;
        }
    }
    cout<<ans;



}
