#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;

int n, k, ans = 0;
vector<int> a;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 0, x; i < n; i++){
        cin>>x;
        a.pb(x);
    }
    int t = n-1, c;
    while(t != -1){
        c = k / a[t];
        ans += c;
        k -= c*a[t];
        t--;
    }
    if(k!= 0) ans = -1;
    cout<<ans;
}
