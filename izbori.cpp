#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 100001
using namespace std;
int n,m;
int b[101];
vector<int> a[101];
int main(){
    cin>>n>>m>>k;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            a[i].pb(j);
        }
    }

    for(int i = 0; i < n; i++){

    }

}
