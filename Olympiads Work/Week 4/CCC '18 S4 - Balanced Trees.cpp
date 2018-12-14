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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
unordered_map<int, ll> dp;

ll solve(int n){
    if (dp[n]) return dp[n];
    if (n<3) {return dp[n] = 1;}
    ll ans = 0;
    int a = sqrt(n);
    for(int i = 1; i <= a;i++){
        ans+=solve(i)*(n/i - n/(i + 1));
        if(i>1 && n/i > a)
            ans+= solve(n/i);
    }
    return dp[n]=ans;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<solve(n);
}
