#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 501
using namespace std;
int n,m1,m2,ans;
int dpa[41][MAXN], dpb[41][MAXN];
vector<int> a,b,c;
int main(){
    MEM(dpa,INF);
    MEM(dpb,INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m1>>m2;
    a.pb(0);b.pb(0);c.pb(0);
    for (int i =0,x,y,z; i < n; i++){
        cin>>x>>y>>z;
        a.pb(x); b.pb(y); c.pb(z);
    }
    for(int i = 0; i < 41; i++){
        dpa[i][0] = dpb[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j < MAXN; j++){
            dpa[i][j] = min(dpa[i-1][j], dpa[i-1][j-a[i]] + c[i]);
        }
        for(int j = b[i]; j < MAXN; j++){
            dpb[i][j] = min(dpb[i-1][j], dpb[i-1][j-b[i]] + c[i]);
        }
    }
    ans = INF;
    for(int i = 1; i < MAXN && MAXN > i*m1 && MAXN > i*m2; i++){
        if(dpa[n][i*m1] != INF && dpb[n][i*m2] != INF){
            vector<int> ia,ib;
            int curx=n, cury=i*m1;
            int cost = dpa[n][i*m1]+dpb[n][i*m1];
            while(curx!=0){
                if(dpa[curx][cury] < dpa[curx-1][cury]){
                    ia.pb(curx);
                    cury-=a[curx];
                    curx--;
                }
                else
                    curx--;
            }
            curx=n, cury=i*m2;
            while(curx!=0){
                if(dpb[curx][cury] < dpb[curx-1][cury]){
                    ib.pb(curx);
                    cury-=b[curx];
                    curx--;
                }
                else
                    curx--;
            }
            vector<int> ex;
            for(int j : ia){
                for(int k :ib){
                    if(j==k)
                        ex.pb(j);
                }
                //cout<<j<<endl;
            }
            UNI(ex);
            for(int j : ex){
                cost -= c[j];
            }
            ans = min(ans, cost);
        }
    }
    cout<<(ans == INF? -1: ans);



}
