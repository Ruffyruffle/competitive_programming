#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 421
using namespace std;
int n;

int dis[MAXN];

int bfs(int cur, int goal, vector<int> *a){
    queue<int> c;
    c.push(cur);
    dis[cur] = 0;

    while(!c.empty()){
        cur = c.front();
        if (cur == goal)
            return dis[cur] + 1;
        for(int i = 0; i < a[cur].size(); i++){
            if(dis[a[cur][i]] == -1){
                dis[a[cur][i]] = dis[cur] + 1;
                c.push(a[cur][i]);
            }
        }
        c.pop();
    }
    return -1;
}

int solve(){
    MEM(dis, -1);
    vector<int> a[MAXN];
    int x,y;
    char c;
    cin>>x>>y;
    for(int i = 0; i < x;i++){
        for(int j = 0; j < y; j++){
            cin>>c;
            int cur = i*y + j;
            if (c == '-'){
                if (j != y-1)
                    a[cur].pb(cur+1);
                if(j!=0)
                    a[cur].pb(cur-1);
            }
            else if(c=='+'){
                if (j != y-1)
                    a[cur].pb(cur+1);
                if(j!=0)
                    a[cur].pb(cur-1);
                if (i!= 0)
                    a[cur].pb(cur-y);
                if (i!= x-1)
                    a[cur].pb(cur+y);
            }
            else if (c=='|'){
                if (i!= 0)
                    a[cur].pb(cur-y);
                if (i!= x-1)
                    a[cur].pb(cur+y);
            }
            else if (c=='*'){
                dis[cur] = INF;
            }
        }
    }
    cout<<bfs(0, x*y - 1, a)<<endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i =0; i < n; i++){
        solve();
    }
}
