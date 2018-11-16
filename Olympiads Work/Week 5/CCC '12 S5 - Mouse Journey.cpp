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
#define MAXN 26
using namespace std;
int r, c, k,x,y;
bool a[MAXN][MAXN];
int DP[MAXN][MAXN];

int solve(int r, int c){
    if (r == 0 || c == 0) return 0;
    if (r == 1 && c == 1) return 1;
    if (DP[r][c]) return DP[r][c];
    if (a[r][c]) return 0;
    DP[r][c] = (solve(r-1, c) + solve(r, c-1));
    return DP[r][c];
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    MEM(a,false);
    cin>>r>>c>>k;
    for (int i =0; i < k; i++){
        cin>>x>>y;
        a[x][y] = true;
    }
    cout<<solve(r,c);
}
