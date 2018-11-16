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
#define MAXN 1002
using namespace std;
int n,m,t;
int dis[MAXN][MAXN];
vector<int> a[MAXN];

void preComp(int root){
    int cur = root;
    queue<int> d; d.push(cur); dis[cur][cur] = 0;
    while(!d.empty()){
        cur = d.front();
        for(int i = 0; i < a[cur].size(); i++){
            if(dis[root][a[cur][i]] == -1){
                dis[root][a[cur][i]] = dis[root][cur] + t;
                d.push(a[cur][i]);
            }
        }
        d.pop();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,y,q;
    cin>>n>>m>>t;
    for (int i =0; i < m; i++){
        cin>>x>>y;
        a[x].pb(y);
    }
    MEM(dis,-1);
    for(int i = 1; i <= n; i++) preComp(i);
    cin>>q;
    for(int i =0; i < q;i++){
        cin>>x>>y;
        if(dis[x][y] == -1) cout<< "Not enough hallways!"<<endl;
        else cout<<dis[x][y]<<endl;
    }
}
