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
#define MAXN 400002
using namespace std;
int n,m,ans,a,c;
int d[MAXN], d2[MAXN];
vector<pii> an, co;
vector<int> xn;
unordered_map<int,int> xx;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>a>>c;
    for (int i =0,x,y; i < a; i++){
        cin>>x>>y;
        an.pb({x,y+1}); xn.pb(x); xn.pb(y+1);
    }
    for (int i =0,x,y; i < c; i++){
        cin>>x>>y;
        co.pb({x,y+1}); xn.pb(x); xn.pb(y+1);
    }
    xn.erase(unique(xn.begin(),xn.end()),xn.end());
    sort(xn.begin(),xn.end());
    for(int i = 0; i < xn.size(); i++){
        xx[xn[i]] = i;
    }
    for(pii i : an){
        d[xx[i.f]]++; d[xx[i.s]]--;
    }
    for(pii i : co){
        d2[xx[i.f]]++; d2[xx[i.s]]--;
    }
    int f=0,g=0; int last = 0;
    for(int i = 0; i < xn.size(); i++){
        if(f && !g) {ans+= xn[i] - last;}
        f+=d[i];
        g+=d2[i];
        last = xn[i];
        //cout<<d2[i]<<endl;
    }
    cout<<ans;



}
