#include<bits/stdc++.h>
#define MAXN 1001
#define pii pair<int,int>
#define f first
#define s second

int n,m;
using namespace std;
vector<pii> a;

bool al[MAXN][MAXN];


int main(){
    int x,y;
    int ans = 0;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        a.push_back({x,y});
    }
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        x--; y--;
        al[x][y] = 1;
        al[y][x] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k< n; k++){
                if(al[i][j] || al[j][k] || al[i][k]) continue;
                if(i==j && i==k) ans = max(ans, a[i].s);
                else if(i==j) ans = max(ans, a[i].s * a[k].f + a[k].s);
                else if(j==k) ans = max(ans, a[i].s * a[k].f + a[k].s);
                else if(i==k) ans = max(ans, a[i].s * a[j].f + a[j].s);
                else ans = max(ans, ((((0+a[i].s)*a[j].f) + a[j].s) * a[k].f) + a[k].s);

            }
        }
    }
    cout<<ans;

}
