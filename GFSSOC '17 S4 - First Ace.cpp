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
#define MAXN 2001
using namespace std;
int n,m,ans;
vector<piii> a;
int dp[MAXN];

//bool cmp(piii a, piii b){return a.s.f < b.s.f;}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y,z; i < n; i++){
        cin>>x>>y>>z;//v,l,t
        a.pb({x,{z,y}});
    }
    //sort(a.begin(),a.end(),cmp);

    for(int i = 0 ; i < n; i++){
        for(int j = MAXN; j >= 0; j--){
            if(j >= a[i].s.s && a[i].s.f >= j){
                dp[j] = max(dp[j], dp[j-a[i].s.s] + a[i].f);
                //if(dp[j] == 4) cout<<"a";
            }
        }
    }
    for(int i = 0; i < MAXN; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;



}
