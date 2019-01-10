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
#define MAXN 1000000
using namespace std;
int n,m,ans;

int gcs(string a, string b){
    int dp[a.length()+1][b.length()+1];
    MEM(dp, 0);
    for(int i = 0; i <= a.length(); i++){
        dp[i][0] = -i;
    }
    for(int i = 0; i <= b.length(); i++){
        dp[0][i] = -i;
    }
    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j], dp[i][j-1])) - 1;
        }
    }
    return dp[a.length()][b.length()];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    string s;
    vector<string> dic;
    for (int i =0; i < n; i++){
        cin>>s;
        dic.pb(s);
    }
    int mi = -1;
    for(int i = 0 ; i < m; i++){
        cin>>s;
        int mx = -INF;
        for(int j = 0 ;j < n; j++){
            int t = gcs(s,dic[j]);
            if(t > mx){
                mx = t; mi = j;
            }
        }
        cout<<dic[mi]<<" ";
    }




}
