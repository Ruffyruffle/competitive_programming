#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m,x,y; ll k;
bool in[MAXN];
ll d[MAXN];

struct train{
    int des, dis, tnum;
    train(int a, int b, int c){
        des = a; dis = b; tnum = c;
    }

};
vector<train> a[MAXN];

ll solve(int cur, int goal, int pass){
      queue<int> f;
      f.push(cur);
      MEM(d,0x3f);
      MEM(in, false);
      d[cur] = 0; in[cur]=1;
      ll dis = 0;
      while(!f.empty()){
        cur = f.front();
        in[cur] = false;
        f.pop();
        for(train i : a[cur]){
            if(i.tnum > pass) continue;
            if(i.dis + d[cur] < d[i.des]){
                d[i.des] = i.dis + d[cur];
                if(!in[i.des]){
                    f.push(i.des);
                    in[i.des] = true;
                }
            }
         }
      }
      return d[goal];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    scan(n); scan(m);
    for (int i=1,d; i <= m; i++){
        scan(x); scan(y); scan(d);
        a[x].pb(train(y,d,i));
        a[y].pb(train(x,d,i));
    }
    scan(x); scan(y); scan(k);
    ll ans = INF;
    int lo = 1, hi = m+1;
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
    cout<<(ans == INF ? -1: ans);
}
