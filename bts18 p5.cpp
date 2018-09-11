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
#define MAXN 100000
using namespace std;
int n;
vector <int> tr[MAXN];
vector <int> tr2[MAXN];
bool visited[MAXN];
int biggest = 0;
ll str[MAXN];

void dfs(int cur, int big){
    visited[cur] = true;
    big++;
    if(big > biggest)
        biggest = big;
    int aa = tr2[cur].size();
    for(int i = 0; i<aa;i++){
        int x = tr2[cur][i];
        if (!visited[x])
            tr2[cur].erase(tr2[cur].begin() + x);
            dfs(x, big);
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>n;
    for (int i =0; i < n-1; i++){
        cin>>str[i];
    }
    for (int i =0; i < n-1; i++){
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    for (int o =1; o < n+1; o++){
        int w = 0;
        MEM(visited, false);
        vector <int> tr2[MAXN] = tr;
        dfs(o,w);
    }
    cout<<biggest<<endl;
}
