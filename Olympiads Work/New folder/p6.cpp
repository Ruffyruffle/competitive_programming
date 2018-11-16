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
#define MAXN 5001
using namespace std;
int n, q;
int a[MAXN];
int sum[MAXN];
map<pair<int, int>, int> d;

int suf(int x, int y){
    if(d[{x,y}] ) return (d[{x,y}]);
    int mn = INF;
    for(int j = x-1; j <= y-1; j++){
        mn = min(mn, a[j]);
    }
    d[{x,y}] = mn * (sum[y] - sum[x-1]);
    return (d[{x,y}]);
    }

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for (int i =0; i < n; i++){
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }
    int x,y;
    for(int i = 0; i < q; i++){
        cin>>x>>y;
        int ans = 0;
        for(int j = x; j <=y ; j++){
            for(int k = j; k <= y; k++){
                ans = max(suf(j,k), ans);
            }
        }
        cout<<ans<<endl;
    }
}
