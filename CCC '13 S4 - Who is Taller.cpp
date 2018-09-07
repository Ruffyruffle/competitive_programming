#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;

int d = 0;
int N;
bool visited[MAXN];
int f[MAXN][MAXN];

void dfs(int cur,int goal){
    visited[cur] = true;
    if (cur == goal){
        d = 1;
    }
    for (int i = 0; i < N; i++) {
        if (f[cur][i] > 0 && !visited[i]) {
        dfs(i,goal);
        }
    }
}


int main(){
    MEM(visited,true);
    int n,m,a,b;
    cin>>n>>m;

    MEM(f,0);
    for (int i =0; i < m; i++){
        cin>>a>>b;
        f[a][b] = 1;
    }
    int cur,goal;
    cin>>cur>>goal;
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    N = n;
    dfs(cur,goal,f);


    if (d==1)
        cout<<"yes";
    else
        cout<<"no";
}
