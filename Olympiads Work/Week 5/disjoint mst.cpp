#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (std::find(s.begin(), s.end(), e) != s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;

int n,m;
vector <int> f[MAXN];

bool dfs(int cur, int goal){
    stack<int> d;
    d.push(cur);
    while(!d.empty()){
        cur = d.top();
        if (cur==goal)
            return true;
        for(int i : f[cur]) d.push(i);
        d.pop();
    }
    return false;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i = 0,a,b; i<m; i++){
        cin>>a>>b;
        f[a].push_back(b);
    }
    int p,q;
    cin>>p>>q;
    if (dfs(p,q))
        cout<<"yes";
    else if (dfs(q,p))
        cout<<"no";
    else
        cout<<"unknown";
}
