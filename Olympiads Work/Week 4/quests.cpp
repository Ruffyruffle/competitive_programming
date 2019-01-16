#include<bits/stdc++.h>

using namespace std;
#define MAXN 5002
#define pb push_back
long long dp[MAXN][2];//[MAXN];
int n,h;
vector<long long> a[4];
int main(){
    cin>>n>>h;
    //for(int i = 0; i < 4; i++) a[i].pb(0);
    for(int i = 0,g,ho,q,t; i < n; i++){ //gi, hi, qi,ti   galong, hreach, qgold, tquest find max
        cin>>g>>ho>>q>>t;
        a[0].pb(g); a[1].pb(ho);
        a[2].pb(q); a[3].pb(t);
    };
//    for(int i = 0; i <= h; i++){
//        for(int j = 1; j <= n; j++){
//            if(dp[i][j] == 0 && j!=1) continue;
//            if(j < n && i+a[1][j+1] <= h)
//                dp[i+a[1][j+1]][j+1] = max(dp[i+a[1][j+1]][j+1],dp[i][j] + a[0][j+1]);
//            if(i+a[3][j] <= h)
//                dp[i+a[3][j]][j] = max(dp[i+a[3][j]][j], dp[i][j]+a[2][j]);
//        }
//    }

    for(int i = 0; i < n; i++){
        int cur = i%2, last = (i+1)%2;
        memset(dp[cur],0,sizeof(dp[cur]));
        for(int j = 1; j <= h; j++){
            if(j-a[1][i] >= 0)
                dp[j][cur] = dp[j-a[1][i]][last] + a[0][i];

            if(j-a[3][i] >= a[1][i])
                dp[j][cur] = max(dp[j][cur], dp[j-a[3][i]][cur] + a[2][i]);
        }
        for(int j = 1; j <= h; j++){
            dp[j][cur] = max(dp[j][cur], dp[j][last]);
        }
//        for(int j = 0; j <=h; j++){
//            cout<<dp[j][cur]<<" ";
//        }
//        cout<<endl;

    }
    long long mx=0;
    for(int i = 1; i <= h; i++){
        mx = max(mx, dp[i][(n-1)%2]);
    }
    cout<<mx;


}
