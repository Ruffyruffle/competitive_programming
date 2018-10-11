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
#define MAXN 1000000
using namespace std;
ll n, m, b = 0, mn = INF;
int main(){
    cin>>n>>m;
    ll a[n];
    for (int i =0; i < n; i++) cin>>a[i];
    ll l = 0, r = 0;
    while(r < n){
        while(m>=b && n>r) {
            b+=a[r++];
        }
        while(b>=m && n>l){
            mn = min(mn, r-l);
            b-=a[l++];
        }
    }
    cout<<((mn > n) ? -1 : mn);
}
