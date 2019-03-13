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
#define MAXN 550
using namespace std;
int n,m,ans;
vector<int> a[MAXN*2];
vector<int> b[MAXN*2];
//int c[MAXN][MAXN];
//int d[MAXN][MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    //cout<<endl;
    for (int i =0,x; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>x;
            a[i+j].pb(x);
        }
    }
    for (int i =0,x; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>x;
            b[i+j].pb(x);
        }
    }
//    for(int i = 0; i < n; i++){
//        int x=i,y=0;
//        while(x>=0 && m>y){
//            a[i].pb(c[y][x]);
//            //cout<<c[y][x]<<" ";
//            x--; y++;
//        }
//        //cout<<endl;
//    }for(int i = 1; i < m; i++){
//        int x=n-1,y=i;
//        while(x>=0 && m>y){
//            a[i].pb(c[y][x]);
//            //cout<<c[y][x]<<" ";
//            x--; y++;
//        }
//        //cout<<endl;
//    }
//    for(int i = 0; i < n; i++){
//        int x=i,y=0;
//        while(x>=0 && m>y){
//            b[i].pb(d[y][x]);
//            //cout<<d[y][x]<<" ";
//            x--; y++;
//        }
//        //cout<<endl;
//    }for(int i = 1; i < m; i++){
//        int x=n-1,y=i;
//        while(x>=0 && m>y){
//            b[i].pb(d[y][x]);
//            //cout<<d[y][x]<<" ";
//            x--; y++;
//        }
//        //cout<<endl;
//    }
    bool t= 1;
    for(int i = 0; i < n+m-1; i++){
        sort(a[i].begin(),a[i].end());
        sort(b[i].begin(),b[i].end());
        for(int j = 0; j < a[i].size(); j++){
            //cout<<a[i][j]<<" "<<b[i][j]<<endl;
            if(a[i][j] != b[i][j]) t=0;
        }
    }
    cout<<(t?"YES":"NO");





}
