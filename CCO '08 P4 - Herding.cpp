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
#define MAXN 1001
using namespace std;
int n,m,ans,k;
char d[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int curx, int cury){
    if(vis[curx][cury]) return;
    vis[curx][cury]=1;
    int a=curx,b=cury;
    if(d[curx-1][cury]=='E') dfs(curx-1,cury);
    if(d[curx][cury-1]=='S') dfs(curx,cury-1);
    if(d[curx+1][cury]=='W') dfs(curx+1,cury);
    if(d[curx][cury+1]=='N') dfs(curx,cury+1);
    if(d[a][b] == 'W') curx--;
    if(d[a][b] == 'S') cury++;
    if(d[a][b] == 'E') curx++;
    if(d[a][b] == 'N') cury--;
    if(!vis[curx][cury])dfs(curx,cury);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
        string s;
    for(int i = 1; i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            d[j][i]=s[j-1];
        }
    }
    for(int i = 1; i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]) {
                dfs(i,j); ans++;
            }
        }
    }
    //cout<<d[4][2];
    cout<<ans;







}
