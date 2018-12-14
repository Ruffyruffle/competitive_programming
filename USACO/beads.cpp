/*
ID: stevenu1
LANG: C++
TASK: beads
*/

#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
bool vis[351];

int main(){
    freopen ("beads.in","r",stdin);
    freopen ("beads.out","w",stdout);

    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s = "";
    cin>>n>>s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int p = i, c = 0;
        char color = s[i];
        MEM(vis, 0);
        while(1){
            if((color == s[p] || s[p] == 'w') && !vis[p]){
                vis[p] = 1;
                c++;
                p = (p==0 ? n - 1 : p-1);
            }
            else{
                break;
            }
        }
        p = (i==n ? 0 : i+1);
        color = s[i+1];
        while(1){
            if((color == s[p] || s[p] == 'w') && !vis[p]){
                vis[p] = 1;
                c++;
                p = (p==(n - 1) ? 0 : p+1);
            }
            else{
                break;
            }
        }
        ans = max(ans, c);
    }
    cout<<ans<<endl;
    return 0;
}
