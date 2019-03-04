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
int n,m,ans,q;
    int k,x,y;
vector<pii> a;

bool cmp(pii a, pii b){
    int d1 = abs(a.f - x)*abs(a.f - x)+abs(a.s - y)*abs(a.s - y);
    return abs(b.f - x)*abs(b.f - x)+abs(b.s - y)*abs(b.s - y) > d1;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        a.pb({x,y});
    }
    while(q--){
        cin>>k>>x>>y;
        sort(a.begin(),a.end(),cmp);
        int ans1=0,ans2=0;
        for(int i = 0; i < k; i++){
            ans1+=a[i].f; ans2+=a[i].s;
        }
        cout<<ans1<<" "<<ans2<<endl;;
    }



}
