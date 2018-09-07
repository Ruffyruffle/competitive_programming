#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>

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
bool visited[MAXN];
bool fuck = false;

//void dfs(int cur, int goal){
//    visited[cur] = true;
//    if (cur == goal)
//        fuck = true;
//    for(int i = 0; i<n; i++){
//
//        if (exists(f[cur], i) && !visited[i]){
//            dfs(i,goal);
//
//    }

//}
void dfs(int cur, int goal){
    queue<int> d;
    d.push(cur);
    visited[cur] = true;
    while(!d.empty()){
        cur = d.front();
        if (cur==goal)
            fuck = true;
        for(int i = 0; i<(int)f[cur].size();i++){
            int next = f[cur][i];
            if (!visited[next]){
                visited[next] = true;
                d.push(next);
            }
        }
        d.pop();
    }
}
int main(){
    cin>>n>>m;
    int a,b;
    for (int i = 0; i<m; i++){
        cin>>a>>b;
        f[a].push_back(b);
    }
    MEM(visited,false);
    int p,q;
    cin>>p>>q;
    dfs(p,q);
    if (fuck)
        cout<<"yes";
    else{
        MEM(visited,false);
        dfs(q,p);
        if (fuck)
            cout<<"no";
        else
            cout<<"unknown";
    }
}
