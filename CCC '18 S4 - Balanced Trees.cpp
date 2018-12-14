#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pii pair<int,int>
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n;
ll dp[MAXN];


//ll fun(int n){
//    if(n==1||n==2) return 1;
//    if(dp[n]) return dp[n];
//    int x = n/2, i = 2, j = n/3; ll ret = n - x;
//    for(; x>=2; x=j, i=n/x, j=n/(i+1))
//        ret+=(x-j)*fun(i);
//    return dp[n] = ret;
//}
//ll fun(int n){
//    if(n==1||n==2) return 1;
//    if(dp[n]) return dp[n];
//    int x = n/2, i = 2, j = n/3; ll ret = n - x;
//    for(; x>=2; x=j, i=n/x, j=n/(i+1))
//        ret+=(x-j)*fun(i);
//    return dp[n] = ret;
//}


ll solve(int n){
    if(dp[n]) return dp[n];
    ll ans = n - n/2;
    int last = n/2;
    for(int i = n/2; i >= n/2; i-= n/(i+1)){
        ans += solve(i) * (i-last);
        last = i;
    }
    return dp[n] = ans;
}

int main(){
    cin>>n;
    dp[1] = 1; dp[2] = 1;
    cout<<solve(n);
}
