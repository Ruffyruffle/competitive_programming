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
int n,m,ans,y,c;
vector<int> v, h;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x,y;
    cin>> x>>y>>n>>m>>c;
    for (int i =0,t; i < n; i++){
        cin>>t; v.pb(t);
    }
    for (int i =0,t; i < m; i++){
        cin>>t; h.pb(t);
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    int x1, x2, y1, y2;
    y1 = *--upper_bound(v.begin(), v.end(),x);
    y2 = *upper_bound(v.begin(), v.end(),x);
    x1 = *--upper_bound(h.begin(), h.end(),x) == --h.begin() ? -1 : *--upper_bound(h.begin(), h.end(),y);
    x2 = *upper_bound(h.begin(), h.end(),y) == h.end() ? 1e7 : *upper_bound(h.begin(), h.end(),y);
    if(y2<y1 || x2<x1) cout<<"a";
    for(int i = 0,a,b; i < c; i++){
        cin>>b>>a;
        if(x2 >= a && a >= x1 && y2 >= b && b >= y1){
            cout<<"Y";
        }
        else cout<<"N";
        cout<<endl;
    }
}
