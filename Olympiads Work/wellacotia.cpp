#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef std::pair<int, int> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1500
using namespace std;
int n,m,k;
int a[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i =1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 0,x,y,t; i < m; i++){
        cin>>x>>y;
        map<int, int> b;
        for(int j = 1; j <= k; j++){
            cin>>t;
            b[t] = j;
        }
        priority_queue<pii,vector<pii>,greater<pii> > q;
        for(int j = x; j <= y; j++){
            q.push({b[a[j]],a[j]});
        }
        for(int j = x; j <= y; j++){
            a[j] = q.top().second; q.pop();
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" "
        ;
    }
}
