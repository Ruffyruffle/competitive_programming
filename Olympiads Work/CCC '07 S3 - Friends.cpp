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
#define MAXN 10000
using namespace std;
int n;
vector<int> a[MAXN];
int dis[MAXN];
int solve(int cur, int goal){
    queue<int> c;
    c.push(cur);
    dis[cur] = 0;

    while(!c.empty()){
        cur = c.front();
        if (cur == goal)
            return dis[cur];
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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int x,y;
    for (int i =0; i < n; i++){
        cin>>x>>y;
        a[x].pb(y);
    }
    while(1){
        cin>>x>>y;
        if(x==y && x==0)
            break;
        MEM(dis, -1);
        int ans = solve(x,y);
        if(ans == -1) cout<<"No" << endl;
        else cout<< "Yes " << ans-1<<endl;
    }
}
