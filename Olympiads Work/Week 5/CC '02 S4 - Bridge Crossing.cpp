#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 102
using namespace std;
int n,m,dp[MAXN];
unordered_map<int,string> ton;
vector<int> a,c;
vector<string> b;

int last[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n;
    string s;
    a.pb(0);
    for (int i = 0,x; i < n; i++){
        cin>>s>>x;
        ton[i] = s;
        a.pb(x);
    }
    MEM(dp, INF);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int mx = -1;
            if(i+j > n)
                continue;
            for(int k = i+1; k <= i+j; k++){
                mx = max(mx, a[k]);
            }
            if(dp[i+j] > dp[i] + mx){
                dp[i+j] = dp[i]+mx;
                last[i+j] = i;
            }
        }
    }
    last[0] = -1;
    int cur = n;
    while(cur != -1){
        cur = last[cur];
        c.pb(cur);
    }
    cout<<"Total Time: "<<dp[n]<<endl;
    reverse(c.begin(),c.end());
    auto cu = &c[2];
    for(int i = 0; i < n; i++){
        if(*cu == i){
            cu++;
            cout<<endl;
        }
        cout<<ton[i]<<" ";
    }
    //cout<<dp[n-1];




}
