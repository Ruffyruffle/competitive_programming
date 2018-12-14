#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ull n,m,ans, mod = 1e9+7;
ull M[2][2] = {{1,0},{0,1}};
ull M2[2][2] = {{1,1},{1,0}};

void mul(ull a[2][2], ull b[2][2])
{
  ull q =  ((a[0][0]*b[0][0])% mod + (a[0][1]*b[1][0]) % mod) % mod;
  ull w =  ((a[0][0]*b[0][1])% mod + (a[0][1]*b[1][1]) % mod) % mod;
  ull e =  ((a[1][0]*b[0][0])% mod + (a[1][1]*b[1][0]) % mod) % mod;
  ull r =  ((a[1][0]*b[0][1])% mod + (a[1][1]*b[1][1]) % mod) % mod;
  a[0][0] =  q; a[0][1] =  w;
  a[1][0] =  e; a[1][1] =  r;
}
void pow(ull n)
{
    if (n > 1) {
        pow(n/2);
        mul(M,M);
    }
    if (n%2 == 1)
        mul(M,M2);
}

int fib(ull n)
{
    pow(n-1);
    return M[0][0] & mod;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<fib(n);
}
