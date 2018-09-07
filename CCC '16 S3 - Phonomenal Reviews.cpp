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
int n,m;
vector<int> roads[MAXN];
vector<int> pho;

int main(){

    cin>>n>>m;
    int a,b;
    for (int i = 0; i<m;i++){
        cin>>a;
        pho.push_back(a);
    }
    for (int i =0; i < n; i++){
        cin>>a>>b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    bfs()


}
