#include<bits/stdc++.h>
long long n;
#define MAXN 10002
using namespace std;
long long dp[MAXN][10];
string s;
//unordered_map<long long,long long> memo;
long long solve(long long cur, long long ch){
    if(dp[cur][ch]) return dp[cur][ch];
    long long ret = 0;
    if(ch == 4){
        for(long long i = cur-1; i >= 0; i--){
            if(s[i] == 'v') ret+= solve(i,3);
        }
    }
    if(ch == 3){
        for(long long i = cur-1; i >= 0; i--){
            if(s[i] == 'o') ret+= solve(i,2);
        }
    }
    if(ch == 2){
        for(long long i = cur-1; i >= 0; i--){
            if(s[i] == 'l') ret++;
        }
    }
    return dp[cur][ch] = ret;
}
int main(){
    long long x,y;
    //string s;
    cin>>s;
    long long ans = 0;
    for(long long i = s.length()-1; i >=0; i--){
        if(s[i] == 'e'){
            ans+=solve(i,4);
        }
    }
    cout<<ans;

}
