#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 500002
using namespace std;
int n;
int big[MAXN], big2[MAXN], par[MAXN], dp[MAXN], l[MAXN];

vector<int> a[MAXN];

void dfs(int cur,int last){
    big[cur] = 0;
    big2[cur] = 0;
    for(int i : a[cur]){
        if(i != last){
            dfs(i,cur);
            par[i] = cur;

            if(big[i] + 1 > big[cur]){
                big2[cur] = big[cur];
                big[cur] = big[i]+1;
                l[cur] = i;
            }
            else if(big[i] + 1 > big2[cur])
                big2[cur] = big[i]+1;
        }
    }
}
void dfs2(int cur, int last){
    for(int i : a[cur]){
        if(i != last){
            if(i == l[cur]){
                dp[i] = max(dp[cur], big2[cur]) + 1;
            }
            else{
                dp[i] = max(dp[cur], big[cur]) + 1;
            }
            dfs2(i,cur);
        }
    }
    dp[cur] = max(dp[cur], big[cur]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y); a[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    int ans = -1, ans2 = -1;
    for(int i = 1; i <=n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            ans2 = i;
        }
    }
    cout<<ans<<" " <<ans2;
}
