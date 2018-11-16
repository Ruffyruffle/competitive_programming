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
#define MAXN 501
using namespace std;
int n;
vector<int> a[MAXN];
bool visited[MAXN];

int bfs(int cur){
    queue<int> f; f.push(cur);
    visited[cur] = true;
    while(!f.empty()){
        cur = f.front();

        for(int i = 0; i < a[cur].size(); i++){
            if(!visited[a[cur][i]]){
                f.push(a[cur][i]);
                visited[a[cur][i]] = true;
            }
        }
        f.pop();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    MEM(visited, false);
    char c;
    cin>>n;
    for (int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>c;
            if(c== '1'){
                a[i].pb(j);
                a[j].pb(i);
                cout<<"a";
            }
        }
    }
    bfs(1);
    for(int i = 0; i < n; i++){
        if(visited[i])
            cout<<i;
    }
}
