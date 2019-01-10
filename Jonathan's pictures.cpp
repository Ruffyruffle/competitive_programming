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
#define MAXN 2002
using namespace std;
int n,m; ll ans;
int cur[MAXN];

struct line{int x, y1, y2, v;};
bool cmp(line a, line b){ return a.x < b.x;}
vector<line> a;
vector<ll> yv;

unordered_map<int,int> yti;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y,x2,y2; i < n; i++){
        cin>>x>>y>>x2>>y2;
        a.pb({x,y2,y,1});
        a.pb({x2,y2,y,-1});
        yv.pb(y); yv.pb(y2);
    }
    UNI(yv)
    sort(yv.begin(), yv.end());
    for(int i = 0; i < yv.size(); i++){
        yti[yv[i]] = i;
    }
    sort(a.begin(),a.end(),cmp);
    int last = 0;
    for(line i : a){
        for(int j = 0; j < yv.size() - 1; j++){
            if(cur[j] > 0)
                ans += (yv[j+1] - yv[j]) * (i.x - last);
        }
        for(int j = yti[i.y1]; j < yti[i.y2]; j++){
            cur[j]+= i.v;
        }
        last = i.x;

    }
    cout<<ans;
}
