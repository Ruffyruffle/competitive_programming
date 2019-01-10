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
#define MAXN 1000000
using namespace std;
int n,m; ll ans;
vector<pii> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i].s - a[j].s != 0){
                ll t = (a[i].f - a[j].f) / (a[j].s - a[i].s);
                //cout<<t<<endl;
                //if(abs(t -(ll)t) < 1e-3){
                    ans = min(ans,max(0ll,(ll)t));
                //}
            }
        }
    }
    cout<<(ans == INF ? -1 : ans);



}
