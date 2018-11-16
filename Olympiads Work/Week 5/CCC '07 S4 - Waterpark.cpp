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
#define MAXN 10000
using namespace std;
int n;
vector<int> a[MAXN], b[MAXN];
int DP[MAXN];
bool visited[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int x = -1, y = -1;
    while(x!=0 && y!=0){
        cin>>x>>y;
        a[x].pb(y);
        b[y].pb(x);
    }
    int cur = 1;
    priority_queue<int, vector<int>, greater<int>> f;
    f.push(1);
    DP[1] = 1;
    while(!f.empty()){
        cur = f.top();
        f.pop();
        if(visited[cur])
            continue;

        visited[cur] = true;
        for(int s : b[cur]){
            DP[cur] += DP[s];
        }
        for(int s : a[cur]){
            if(!visited[s])
                f.push(s);
        }
    }
    cout<<DP[n];
}
