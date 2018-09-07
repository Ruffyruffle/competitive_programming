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
#define MAXN 100000
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
using namespace std;

int main(){
    int a[MAXN], n;
    cin>>n;
    MEM(a,0);
    for(int i = 0; i <n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll b = 0;

    for(int i = 0; i <n; i++){
        b+=(((a[i]%10007)*(a[n-1-i]))%10007);
    }
    cout<<b%10007;
}
