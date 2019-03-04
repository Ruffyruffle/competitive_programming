#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 301
using namespace std;
int n,m,ans,q;
int d[MAXN][MAXN];
int main(){
    MEM(d,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i =0,x,y,z; i < m; i++){
        cin>>x>>y>>z;
        d[x][y]=d[y][x]=min(d[x][y],z);
        d[i][i]=0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                d[j][k] = min(d[j][i] + d[i][k], d[j][k]);
            }
        }
    } int x,y;
    while(q--){
        cin>>x>>y;
        cout<<(d[x][y]==INF?-1:d[x][y])<<endl;
    }



}
