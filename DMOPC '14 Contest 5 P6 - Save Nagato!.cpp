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
#define MAXN 500001
using namespace std;
int n;
vector <int> tr[MAXN];
bool visited[MAXN];
int biggest[MAXN];


void dfs(int cur, int big, int node){
    visited[cur] = true;
    big++;
    if(big > biggest[node])
        biggest[node] = big;
    //cout<<"a"<<tr[cur].size()<<"a";
    for(int i = 0; i<tr[cur].size();i++){
        int x = tr[cur][i];
        if (!visited[x])
            dfs(x, big, node);
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>n;
    MEM(biggest, 0);
    for (int i =0; i < n-1; i++){
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    for (int o =1; o < n+1; o++){
        int w = 0;
        MEM(visited, false);
        dfs(o,w,o);
        cout<<biggest[o]<<endl;
    }
}
