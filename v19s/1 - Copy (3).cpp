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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m; ld a[MAXN];
ll ans = INF;
ll psa[MAXN];
//
//ll solve(int cur, int curi, int mask, ll ret){
//    ret = max(ret, psa[cur + a[curi]] - psa[cur-1])
//}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =1; i <= n; i++){
        cin>>a[i];
        psa[i] = psa[i-1] + a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>a[i];
        //dans = min(ans, solve(1,i,1<<i, 0));
    }
    if(m==3){
        for(int i = 0; i <= n; i++){
            for(int j = i; j <= n; j++){
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[0], (psa[j] - psa[i])/a[1]), (psa[n] - psa[j]) / a[2])));
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[0], (psa[j] - psa[i])/a[2]), (psa[n] - psa[j]) / a[1])));
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[1], (psa[j] - psa[i])/a[2]), (psa[n] - psa[j]) / a[0])));
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[1], (psa[j] - psa[i])/a[0]), (psa[n] - psa[j]) / a[2])));
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[2], (psa[j] - psa[i])/a[1]), (psa[n] - psa[j]) / a[0])));
                ans = min(ans, (ll)ceil(max(max((psa[i] - psa[0])/a[2], (psa[j] - psa[i])/a[0]), (psa[n] - psa[j]) / a[1])));
            }
        }
    }
    else if(m==2){
        for(int i = 0; i <= n; i++){
            ans = min(ans, (ll)ceil(max((psa[n]-psa[i])/a[0], (psa[i] - psa[0])/a[1])));
            ans = min(ans, (ll)ceil(max((psa[n]-psa[i])/a[1], (psa[i] - psa[0])/a[0])));
        }
    }
    else if(m==1){
        ans = ceil((psa[n] - psa[0]) /a[0]);
    }
    //cout<<max(max((psa[4] - psa[3])/a[0], (psa[3] - psa[0])/a[1]), (psa[5] - psa[4]) / a[2])<<endl;
    cout<<ans;



}
