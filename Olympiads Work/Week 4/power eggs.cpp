#include<bits/stdc++.h>
using namespace std;
#define MAXN 33
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
unsigned int dp[MAXN][MAXN],x,y,t;//,n=32;
inline void precomp(){
//    for(char i = 0 ; i < MAXN; i++){
//        dp[i][0] = 1;
//        dp[0][i] = 1;
//    }
    for(char i = 1 ; i < 10; i++){
        for(char j = 1 ; j < 10; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1]+1;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    scan(t);
    precomp();
    while(t--){//for(int i = 0,x,y; i < t; i++){
        scan(x); scan(y);
        if(x > dp[y][32]) printf("Impossible\n");
        else printf("%d\n", lower_bound(dp[y], dp[y]+32, x)-dp[y]);
    }



}
