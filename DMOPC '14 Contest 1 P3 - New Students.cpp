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
int n,k;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    double ans = 0;
    cin>>n;
    int x;
    for (int i =0; i < n; i++){
        cin>>x;
        ans += x;
    }
    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>x;
        ans += x;
        cout<<ans/(n+i+1)<<'\n';
    }

}
