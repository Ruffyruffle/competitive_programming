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
#define MAXN 100
using namespace std;
int n,q;

vector<pair<int,int>> p[MAXN];
int dis[MAXN][MAXN];

void preComp(){
    for(int i = 0; i < n; i++){
        queue<int> d;
        int cur = i;
        dis[i][cur] = 0;

        while(!d.empty()){
            cur = d.front();

            for(int j = 0; j < p[cur].size(); j++){
                int next = p[cur][i].first;
                if (dis[i][next] == -1){
                    dis[i][next] = dis[i][cur]+p[cur][i].second;
                    d.push(next);
                }
            }
            d.pop();
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>n;
    memset(dis, -1, sizeof(dis[0][0]) * n * n);
    for (int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a;
            if(a!='0'){
                p[i].pb(make_pair(j,a));
            }
        }
    }
    preComp();
    cin>>q;
    for(int i = 0; i<q; i++){

    }





}
