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
#define MAXN 101
using namespace std;
int n;

void solve(){
    vector<int> a[MAXN];
    int mx = 0;
    int dis[MAXN];
    MEM(dis,-1);
    string x,y;
    cin>>n;
    int cur;
    unordered_map<string, int> name;
    for (int i =0; i < n; i++){
        y = x;
        cin>>x;
        if(name.find(x) == name.end())
            name[x] = i;
        if(i != 0){
            a[name[x]].pb(name[y]);
            a[name[y]].pb(name[x]);
        }
        if(i==n-1){
            cur = name[x];
        }
    }
    queue<int> d;
    d.push(cur);
    dis[cur] = 0;
    while(!d.empty()){
        cur = d.front();
        mx = max(dis[cur], mx);
        for(int i = 0; i < a[cur].size(); i++){
            if(dis[a[cur][i]] == -1){
                dis[a[cur][i]] = dis[cur] + 1;
                d.push(a[cur][i]);
            }
        }
        d.pop();
    }
    cout<< ((n * 10) - (2* mx * 10));
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        solve();
        cout<<endl;
    }
}
