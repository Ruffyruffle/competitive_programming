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
#define MAXN 300
using namespace std;
int n,x,y,x2,y2,v,d,q,z,z2;
int bit[MAXN][MAXN][MAXN];
short a[MAXN][MAXN][MAXN];
void add(int i,int j, int k,int val){
    int t = j, t2 = k;
    while(i <= q*2){
        while(j<= q*2){
            while(k <= q*2){
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

struct query{
    char c;
    int x,y,z,v,x2,y2,z2;
};
vector<query> qu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(q);
    char c;

    vector<int> xv,yv,zv;

    ll ans = 0;
    for(int i = 0; i < q; i++){
        c = getchar();
        if(c=='U'){
            scan(x); scan(y); scan(z); scan(v);
            qu.pb({c,x,y,z,v,0,0,0});
            xv.pb(x); yv.pb(y); zv.pb(z);
        }
        else if (c == 'S'){
            scan(x); scan(y); scan(z); scan(x2); scan(y2); scan(z2);
            x--;y--;z--;
            qu.pb({c,x,y,z,0,x2,y2,z2});
            xv.pb(x); yv.pb(y); zv.pb(z);
            xv.pb(x2); yv.pb(y2); zv.pb(z2);
        }
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());
    unordered_map<int,int> xx,yy,zz;
    for(int i = 1; i <= xv.size(); i++){
        xx[xv[i-1]] = i;
        yy[yv[i-1]] = i;
        zz[zv[i-1]] = i;
    }
    n = xv.size();
    for(int i = 0 ; i < q; i++){
        char c = qu[i].c;
        x = xx[qu[i].x]; x2 = xx[qu[i].x2];
        y = yy[qu[i].y]; y2 = yy[qu[i].y2];
        z = zz[qu[i].z]; z2 = zz[qu[i].z2];
        v = qu[i].v;
        if(c=='U'){
            d = v - a[x][y][z];
            a[x][y][z] = v;
            add(x,y,z,d);
        }
        else if (c == 'S'){
            cout<<(sum(x2,y2,z2) - sum(x, y2, z2) - sum(x2,y,z2) - sum(x2, y2, z)
            + sum(x,y,z2) + sum(x,y2,z) + sum(x2,y,z) - sum(x,y,z))<<endl;
        }
    }

}
