#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;

struct line{
    int x, y1, y2, t;
    line(int a, int b, int c, int d){
        x = a; y1 = b; y2 = c; t = d;
    }
};

bool cmp(line a, line b){return b.x > a.x;}
vector<line> a;
int tint[2002];
unordered_map<int, int> yrank;
vector<int> y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin>>n>>t;

    for(int i = 0,x1,x2,y1,y2,t; i < n; i++){
        cin>>x1>>y1>>x2>>y2>>t;
        a.pb(line(x1,y1,y2,t));
        a.pb(line(x2,y1,y2,-t));
        y.pb(y1); y.pb(y2);
    }
    sort(a.begin(), a.end(), cmp);
    y.erase(unique(y.begin(), y.end()), y.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < y.size(); i++){
        yrank[y[i]] = i;
    }

    ll ans = 0, last = 0;

    for(line f : a){
        for(int i = 0; i < y.size() - 1; i++){
            if(tint[i] >= t){
                ans += (y[i+1] - y[i]) * (f.x - last);
            }
        }
        for(int i = yrank[f.y1]; i < yrank[f.y2]; i++){
            tint[i] += f.t;
        }
        last = f.x;
    }
    cout<<ans;
}
