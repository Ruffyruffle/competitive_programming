#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1001
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll d[MAXN];//[MAXN];
int n,m;
bool c[MAXN][MAXN];
vector<pii> a[MAXN];
int main(){
    memset(d, INF, sizeof(d));
    cin>>n>>m;
    for(ll i =0,x,y,z; i < m; i++){
        cin>>x>>y>>z;
        //d[x][y] = min(d[x][y], z);
        a[x].pb({z,y});
    }




//    for(int i = 1; i<=n; i++){
//        d[i][i] = 0;
//    }
//
//    for(int k = 1; k <= n; k++){
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <=n; j++){
//                if(d[i][k] == INF || d[k][j] == INF) continue;
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//            }
//        }
//    }
//    for(int k = 1; k <= n; k++){
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <=n; j++){
//                if(d[i][k] + d[k][j] < d[i][j]) c[i][j] =1;
//                //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//            }
//        }
//    }
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <=n; j++){
//            if(d[i][j] == INF) cout<<"INF";
//            else if(c[i][j]) cout<<"-INF";
//            else cout<<d[i][j];
//            if(j!=n) cout<<" ";
//        }
//        if(i!=n)cout<<endl;
//    }

}
