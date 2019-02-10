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
#define MAXN 3001
using namespace std;
int n,m,ans;
int dp[MAXN][101][101][2];
//vector<int> a,f;
int a[MAXN],f[101];
int solve(int cur, int l, int r, int t){
    //cout<<cur<<" "<<l<<" "<<r<<" "<<t<<endl;
    if(dp[cur][l][r][t]) return dp[cur][l][r][t];
    if(cur==n && l>r) return 0;
    if(cur==n){
        if(t) return dp[cur][l][r][t] = solve(cur,l,r-1,0) + f[r];
        return dp[cur][l][r][t] = solve(cur,l+1,r,1);
    }
    if(t){
        if(l>r) return dp[cur][l][r][t] = dp[cur+1][l][r][0] + a[cur];
        return dp[cur][l][r][t] = max(solve(cur+1,l,r,0) + a[cur], solve(cur,l,r-1,0) + f[r]);
    }
    if(l>r) return dp[cur][l][r][t] = max(solve(cur+1,l,r,1), solve(cur+1,l,r,0));
    return dp[cur][l][r][t] = max(max(max(solve(cur+1,l,r,1), solve(cur+1,l,r,0)), solve(cur,l+1,r,1)), solve(cur,l+1,r,0));
//    if(cur == n)
//        if(t) return dp[cur][l][r][t] = solve(cur,l+1,r,0);
//        else return dp[cur][l][r][t] = max(solve(cur,l,r-1,1) + f[r], solve(cur,l+1,r,0));
//    if(t){
//        if(l>r) return dp[cur][l][r][t] = solve(cur+1,l,r,0);
//        return dp[cur][l][r][t] = max(solve(cur+1,l,r,0), solve(cur,l+1,r,0));
//    }
//    if(l>r) return dp[cur][l][r][t] = max(solve(cur+1,l,r,1) + a[cur], solve(cur+1,l,r,0));
//    return dp[cur][l][r][t] = max(max(max(solve(cur,l,r-1,1) + f[r], solve(cur+1,l,r,1) + a[cur]), solve(cur+1,l,r,0)), solve(cur,l+1,r,0));
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i = 0,x; i < m; i++){
        cin>>f[i];
    }
    //sort(a.begin(),a.end());
    sort(f,f+m);
    cout<<max(solve(0,0,m-1,1),solve(0,0,m-1,0));
}
