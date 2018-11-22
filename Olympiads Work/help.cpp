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
#define MAXN 100001
using namespace std;
int n,m,k,x,y;
bool in[MAXN];

struct train{
    int des, dis, tnum;
    train(int a, int b, int c){
    des = a; dis = b; tnum = c;
    }

};
vector<train> a[MAXN];

int solve(int cur, int goal, int pass){
    priority_queue<pii,vector<pii>,greater<pii> > f;
    f.push({0,cur});
    int d[m];
    MEM(d, INF);
    d[cur] = 0;
    while(!f.empty()){
        cur = f.top().second; f.pop();
        for(train i : a[cur]){
            if(d[i.des] > d[cur] + i.dis && i.tnum <= pass){
                d[i.des] = d[cur] + i.dis;
                f.push({d[i.des], i.des});
            }
        }
    }
    return d[goal];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
        for (int i=1,d; i <= n; i++){
        cin>>x>>y>>d;
        a[x].pb(train(y,d,i));
        a[y].pb(train(x,d,i));
    }
    cin>>x>>y>>k;
    int ans = INF;
    int lo = 1, hi = m;
      while(lo <= hi){
        int mid = (lo+hi) / 2;
        if(solve(x,y,mid) <= k){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<(ans == INF? -1: ans);
}

