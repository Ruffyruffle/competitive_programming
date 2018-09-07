#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iterator>

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
int n;
bool decend(int i , int j) {return i>j;}

int main(){
    int a,ans=0;
    cin>>a>>n;
    int d[n];
    int p[n];
    for (int i =0; i < n; i++) cin>>d[i];
    for (int i =0; i < n; i++) cin>>p[i];
    sort(d, d + n);
    if (a == 2)
        sort(p, p + n, decend);
    else
        sort(p, p + n);
    for (int i = 0; i < n; i++) ans+=(max(d[i], p[i]));
    cout<<ans;
}
