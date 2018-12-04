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
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 251
using namespace std;
int n,x,y,x2,y2,v,d,q,z,z2;
ll bit[MAXN][MAXN][MAXN];
int a[MAXN][MAXN][MAXN];
void add(int i,int j, int k,int val){
    int t = j, t2 = k;
    while(i <= n){
        while(j<= n){
            while(k <=n){
                bit[i][j][k] += val;
                k+=(-k&k);
            }
            j+=(-j&j);
            k = t2;
        }
        i+=(-i&i);
        j = t;
    }
}

ll sum(int i, int j, int k){
    ll ans = 0, t = j, t2 = k;
    while(i > 0){
        while(j>0){
            while(k>0){
                ans+=bit[i][j][k];
                k-=(k&-k);
            }
            j-=(j&-j);
            k = t2;
        }
        i-=(i&-i);
        j = t;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(q);
    char c;
    ll ans = 0;
    for(int i = 0; i < q; i++){
        c = getchar();
        if(c=='C'){
            scan(x); scan(y); scan(z); scan(v);
            d = v - a[x][y][z];
            a[x][y][z] = v;
            add(x,y,z,d);
        }
        else if (c == 'S'){
            scan(x); scan(y); scan(z); scan(x2); scan(y2); scan(z2);
            x--;y--;z--;
            ans+=(sum(x2,y2,z2) - sum(x, y2, z2) - sum(x2,y,z2) - sum(x2, y2, z)
            + sum(x,y,z2) + sum(x,y2,z) + sum(x2,   y,z) - sum(x,y,z));
        }
    }
    cout<<ans;
}
