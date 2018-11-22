#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back

typedef std::pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1605
using namespace std;
int n,m,k,x,y;
int h[MAXN];
int d[MAXN];

struct route{
    int des, dis, wear;
    route(int a, int b, int c){
    des = a; dis = b; wear = c;
    }

};
vector<route> a[MAXN];

int main(){
    MEM(d, INF);
    MEM(h, -1);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>n>>m;
    for (int i =1,d,w; i <= m; i++){
        cin>>x>>y>>d>>w;
        a[x].pb(route(y,d,(w==1 ? d : 0)));
        a[y].pb(route(x,d,(w==1 ? d : 0)));
    }
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int, pii>>> f;
    f.push({0,{k,0}});
    d[0] = 0;
    while(!f.empty()){
        int cur = f.top().second.second;
        int dist = f.top().first;
        int he = f.top().second.first; f.pop();
        for(route i : a[cur]){
            int dc = dist + i.dis; int wc = he - i.wear;
            if((d[i.des] > dc || wc > h[i.des] )&& wc >= 0){
                d[i.des] = min(d[i.des], dc);
                h[i.des] = max(h[i.des], wc);
                f.push({dc, {wc, i.des}});
            }
        }
    }
    cout<<(d[n-1] == INF ? -1 : d[n-1]);
}
