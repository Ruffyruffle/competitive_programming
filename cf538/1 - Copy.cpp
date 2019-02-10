#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 200001
using namespace std;
int n,m,k;
int a[MAXN]; int c[MAXN];
vector<pii> b;
vector<int> ans;
bool cmp(pii a, pii b){
    return a.s < b.s;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i =0; i < n; i++){
        cin>>a[i]; b.pb({a[i], i});
    }
    sort(b.begin(),b.end()); reverse(b.begin(),b.end());
    int l = min(n,m*k);
    sort(b.begin(), b.begin() + l, cmp);
    ll ans2 = 0;
    for(int i = 0; i < l; i++){
        c[b[i].s] = -1;
        ans2+=b[i].f;
    }
    int part = 0;

    for(int i = 0; i < l; i+=m){
        if(c[b[i].s] && c[b[i].s]!=-1) continue;
        int p = 1;
        c[b[i].s] = part;
        ans.pb(b[i].s);
        part++;

        int j = b[i].s;
        while(p < m){
            j++;
            if(c[j] == -1){
                p++;
            }
            c[j] = part;
        }
    }
    if(ans[0] == 0) ans.erase(ans.begin());
    cout<<ans2<<endl;
    for(int i : ans){
        cout<<i<<" ";
    }


}
