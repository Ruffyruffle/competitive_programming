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
int mp[MAXN];
int d[MAXN];

struct train{
    int des, dis, tnum;
    train(int a, int b, int c){
    des = a; dis = b; tnum = c;
    }

};
vector<train> a[MAXN];

int main(){
    MEM(d, INF);
    MEM(mp, INF);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i =1,d; i <= n; i++){
        cin>>x>>y>>d;
        a[x].pb(train(y,d,i));
        a[y].pb(train(x,d,i));
    }
    cin>>x>>y>>k;

    queue<int> f; f.push(x);
    queue<int> m; m.push(0);
    queue<int> dis; dis.push(0);
    mp[x] = 0;
    d[x] = 0;

    while(!f.empty()){
        int cur = f.front(); f.pop();
        int mx = m.front(); m.pop();
        int dist = dis.front(); dis.pop();

        for(train i : a[cur]){
            int dd = dist + i.dis;
            int mm = max(i.tnum, mx);

            if((mp[i.des] > mm || dd < d[i.des]) && dd <= k){
                mp[i.des] = min(mm, mp[i.des]);
                d[i.des] = min(dd, d[i.des]);
                f.push(i.des);
                dis.push(dd);
                m.push(mm);
            }
        }
    }
    cout<<(mp[y] == INF ? -1 : mp[y]);
}
/*
4 4
1 4 10
1 2 3
3 4 2
2 3 1
1 4 9
*/
