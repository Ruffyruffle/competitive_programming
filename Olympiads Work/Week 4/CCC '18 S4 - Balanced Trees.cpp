#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unordered_map>

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
int n;
unordered_map<int, ll> dp;

ll solve(int n){
    if (n==1||n==2) return 1;
    if (dp[n]) return dp[n];
    ll ans = n-n/2;
    int j = n/3;
    for(int i = n/2; i >=2; i = n/i - n/(i-1)){
        j = n/i - (n/(i+1));
        ans+= (i-j) * solve(n/i);
    }
    dp[n] = ans;
    return ans;
}
int main(){
    cin>>n;
    cout<<solve(n);
}



ll fun(int n){
    if(n==1||n==2) return 1;
    if(dp[n]) return dp[n];
    int x = n/2, i = 2, j = n/3; ll ret = n - x;
    for(; x>=2; x=j, i=n/x, j=n/(i+1))
        ret+=(x-j)*fun(i);
    return dp[n] = ret;
}




