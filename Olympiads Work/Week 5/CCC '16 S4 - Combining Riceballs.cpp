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
int ps[MAXN];
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
    l--;r--;
    if (l == r) return a[l];
    return ps[r] - ps[l];
}
int solve(int l, int r){
    cout<<l<< " " << r<< endl;
    if(dp[l][r]!= -1) return dp[l][r];
    if(l==r) {
        dp[l][r] = 1;
        return 1;
    }
    if(l+1 == r) {
        dp[l][r] = (a[l] == a[r])? 1 : 0;
        return dp[l][r];
    }

    int p = 1, k = 1;

    if (a[l] == a[r]){
        if (solve(l+1, r-1)){
                dp[l][r] = 1;
                return 1;
        }
    }

    cout<<Sum(l, l+p);
    while(l+p != r-k){
        if (Sum(l, l+p) == Sum(r-k, r)){
            if (solve(l,l+p) == 1 && solve(r,r-k) == 1){
                if (solve(l+p, r-k)){
                dp[l][r] = 1;
                return 1;
                }
            }

        }
        if(solve(l,l+p) == 1 && solve(r,r-k) == 1){
            if (solve(l+p, r-k)){
                dp[l][r] = 1;
                return 1;
            }
        }
        else if (Sum(l, l+p) > Sum(r-k, r))
            p++;
        else
            k++;
    }
    dp[l][r] = 0;
    return 0;
}


int main(){
    cin>>n;
    for (int i =1; i <= n; i++){
        cin>>a[i];
        if (a[i] > mx) mx = a[i];
        ps[i] = ps[i-1] + a[i];
    }

    MEM(dp, -1);


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

