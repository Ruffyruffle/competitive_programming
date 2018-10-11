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
#define MAXN 400
using namespace std;
int n;
int dp[MAXN][MAXN];
int a[MAXN];
int mx;

//int solve(int l, int r){
//    if(dp[l][r] != -1) return dp[l][r];
//    if (l == r) return 1;
//    int p = l+1, k = r-1;
//    for(int i = 0; i < r-l; i++){
//        if (l == r || abs(l-r) == 1){
//            if (a[p] - a[l] == a[r] - a[k] && dp[p][l] && dp[k][r]){
//                if (a[r] - a[l] > mx) mx = a[r] - a[l];
//                dp[l][r] = 1;
//                return 1;
//                }
//            else {
//                dp[l][r] = 0;
//                return 0;
//            }
//        if (a[p] + a[l] > a[r] - a[k]){
//            k--;
//            solve(l+p, r-k);
//        }
//        else{
//            p++;
//            solve(l+p, r-k);
//        }
//    }
//    }
//}

int Sum(int l, int r){
    if (l == r) return a[l];
    return ps[r] - ps[l-1];
}
int solve(int l, int r){
    if (l==r){
        dp=[l][r] = true;
    }
    else if (r-l < 3){
        if(Sum(i,i) == Sum(j,j)){
            dp[i][j] = true;
        }
    }


}


int main(){
    cin>>n;
    for (int i =1; i <= n; i++){
        cin>>a[i];
        a[i] = a[i-1] + a[i];
    }

    MEM(dp, -1);
    for(int h =0; h < n; h++){
        for(int i = 1; i < n+1; i++){
            int j = i+h;
            if(j<=n)
                solve(i,j);
        }
    }


//    for(int i =1; i<=n; i++){
//        dp[i][i] = 1;
//    }

    solve(1, n);
    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    //cout<<mx;
}

