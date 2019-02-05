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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,m;
vector<int> a[MAXN];
vector<int> pho;
int mark[MAXN],len[MAXN],len2[MAXN],lid[MAXN],dp[MAXN];

void check(int cur, int last){
    for(int i : a[cur]){
        if(i == last) continue;
        check(i, cur);
        mark[cur] += mark[i];
    }
}

void dfs(int cur, int last){
    for(int i : a[cur]){
        if (i == last){continue;}
        if(mark[i] == 0) continue;
        dfs(i, cur);
        if(len[i] + 1 > len[cur]){
            len2[cur] = len[cur];
            len[cur] = len[i] + 1;
            lid[cur] = i;
        }
        else if(len[i] + 1 > len2[cur]){
            len2[cur] = len[i] + 1;
        }
    }
}

void dfs2(int cur, int last){
    for(int i : a[cur]){
        if(i == last) continue;
        if(mark[i] == 0) continue;
        if(i == lid[cur]){
            dp[i] = max(dp[cur] , len2[cur]) +1;
        }
        else{
            dp[i] = max(dp[cur], len[cur]) + 1;
        }
        dfs2(i, cur);
    }
    dp[cur] = max(dp[cur], len[cur]);
}

int main(){

    scan(n); scan(m);
    for (int i = 0,x; i<m;i++){
        scan(x);
        pho.push_back(x);
        mark[x] = 1;
    }
    for (int i =0,x,y; i < n-1; i++){
        scan(x); scan(y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    check(pho[0], -1);
    dfs(pho[0], -1);
    dfs2(pho[0], -1);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i] + 1);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mark[i] > 0){
            cnt++;
            //cout<<i<<endl;
        }
    }
    //cout<<ans<<" " <<cnt<<endl;
    cout<< ans + (cnt - ans) * 2 - 1;

}
