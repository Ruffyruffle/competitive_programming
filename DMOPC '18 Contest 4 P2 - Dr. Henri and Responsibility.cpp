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
#define MAXN 700
using namespace std;
int n,m,x,s,ans = 0,mx = 0;
vector<int> a;
bool dp[700*700+2];
int nm[700*700+2];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0,x; i < n; i++){
        cin>>x; s+=x;
        a.pb(x);
    }
    int s2 = s/2;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        MEM(nm, 0); nm[0] = 0;
        for(int j = a[i]; j <= s2; j++){
            if(dp[j-a[i]] && !dp[j]){
                dp[j] = 1;
                nm[j] = nm[j-a[i]] +1;
                ans = max(ans, j);
            }
        }
    }
    cout<< s - ans*2;
}
