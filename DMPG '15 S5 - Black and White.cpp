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
#define MAXN 10001
using namespace std;
int n,m,ans;
int f[MAXN];
struct line{
    int x,y,y2,v;
};
vector<line> a; vector<int> yy;
bool cmp(line a, line b){return b.x > a.x;}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y,w,h; i < m; i++){
        cin>>x>>y>>w>>h;
        a.pb({x,y,y+h,1});
        a.pb({x+w,y,y+h,-1});
        yy.pb(y); yy.pb(y+h);
    }
    sort(a.begin(), a.end(),cmp);
    sort(yy.begin(), yy.end());
    UNI(yy); unordered_map<int,int> o;
    for(int i = 0; i < yy.size(); i++){
        o[yy[i]] = i;
    }
    int last = 0;
    for(line i : a){
        //cout<<i.x<<" "<<last<<endl;
        for(int j = 0; j < yy.size()-1; j++){
            if(f[j]%2==1) ans+=(i.x-last)* (yy[j+1] - yy[j]);
        }
        for(int j = o[i.y]; j < o[i.y2]; j++){
            f[j]+=i.v;
        }
        last = i.x;
    }
    cout<<ans;



}
