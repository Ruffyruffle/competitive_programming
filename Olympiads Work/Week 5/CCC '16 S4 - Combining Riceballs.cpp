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

int Sum(int l, int r){
    return ps[r] - ps[l-1];
}
int solve(int l, int r){
    //cout<<l<< " " << r<< endl;
    if(r>l) return 0;
    if(dp[l][r]) return dp[l][r];
    if(r-l == 0) return dp[l][r] = 1;
    if(r-l == 1) return (a[l]==a[r] ? dp[l][r] = 1 : 0);
    if(r-l == 2 && a[l]==a[r]) return dp[l][r] = 1;

    int ll = l, rr = r;
    for(int l2 = ll; l2 <= rr; l2++){
        for(int r2 = rr; r2 >= ll; r2++){
            if(r2>l2) continue;
            if(ll==)
        }
    }
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

