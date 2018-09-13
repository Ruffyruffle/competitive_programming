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
int n,m,k,x;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>x;
    int f[n+1];
    int grx = 0;
    f[0] = 0;
    for (int i =1; i < n+1; i++){
        cin>>f[i];
        if (f[i] < x)
            grx++;
    }
    sort(f,f+n+1);
    for(grx--)
        if







}
