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
#define MAXN 10001
using namespace std;
int n,m,ans, dp[MAXN],t;
int a[3][2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>t; int x,y;
    for (int i =1; i <= n; i++){
//        for(int j = 0; j < 3; j++){
//            cin>>x>>y;
//            for(int k = x; k <= t; k++){
//                if(i%2==1){
//                    dp[1][k] = max(dp[1][k],max(dp[0][k-x] + y, dp[0][k]));
//                }
//                else{
//                    dp[0][k] = max(dp[0][k],max(dp[1][k-x] + y, dp[1][k]));
//                }
//
//            }
//        }
        for(int j = 0; j < 3; j++){
            cin>>a[j][0]>>a[j][1];
        }
        for(int j = t; j >= 0; j--){
            int mx = dp[j];
            for(int k = 0 ; k < 3; k++){
                if(j>= a[k][0]) mx = max(mx, dp[j-a[k][0]] + a[k][1]);
            }
            dp[j] = mx;
        }

    }
    cout<<dp[t];



}
