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
#define MAXN 12
using namespace std;
int n,m,ans;
char a[MAXN][MAXN][MAXN];
void dfs(int z, int x, int y){
    if(a[z][x][y] != '.') return;
    ans++;
    a[z][x][y] = 'a';
    dfs(z,x-1,y);dfs(z,x+1,y);
    dfs(z,x,y+1);dfs(z,x,y-1);
    dfs(z+1,x,y);dfs(z-1,x,y);
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0); int x,y,z;
    cin>>x>>y>>z;
    string s;
    for (int i =1; i <= x; i++){
        for(int j= 1; j<=y; j++){
            cin>>s;
            for(int k = 1; k <= z; k++){
                a[i][j][k] = s[k-1];
            }
        }
    }
    int cx,cy;
    cin>>cx>>cy;
    dfs(1,cx,cy);
    cout<<ans;
}
