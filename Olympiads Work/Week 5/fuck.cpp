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
#define MAXN 100000
using namespace std;
int n,k,r=0,dis=0; ll ans=0;
unordered_map<int,int> cou;
vector<int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(k);
    for(int i =0,x; i < n; i++){
        scan(x); a.pb(x);
    }
    for(int i = 0; i < n; i++){
        while(n > r && k > dis){
            if(cou[a[r]] == 0)
                dis++;
            cou[a[r]]++;
            r++;
        }
        if(dis == k)
            ans+= n-r+1;

        if(cou[a[i]] == 1)
            dis--;
        cou[a[i]]--;
    }
    cout<<ans<<'\n';
}
