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
int n,m;
vector<pair<int, pair<int, int> > > a;
vector<int> par, rk;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i =0,x,y,z; i < m; i++){
        cin>>x>>y>>z;
        a.pb({i,{x,y}});
    }
    sort(a.begin(), a.end());




}
