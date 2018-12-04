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
#define MAXN 1000000
using namespace std;
int a[101][101];
int dp[101][101];
int n,ans=0;

int solve(int i,int j, int sum){
    if (i == n+1)
        return sum;
    return max(solve(i+1, j+1, sum+a[i+1][j+1]), solve(i+1, j, sum+a[i+1][j]));
}

int main(){
    MEM(a,0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        ans = max(dp[n-1][i], ans);
    }
    cout<<ans;





}
