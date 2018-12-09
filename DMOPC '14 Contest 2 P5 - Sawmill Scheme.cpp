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
#define MAXN 1000001
using namespace std;
int n,m;
vector<int> a[MAXN];
double c[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<std::setprecision(10);
    scan(n);scan(m);
    for (int i =0,x,y; i < m; i++){
        scan(x); scan(y);
        a[x].pb(y);
    }

//    queue<int> f;
//    f.push(1);
//    int cur = 1;
    c[1] = 1;
//    while(!f.empty()){
//        cur = f.front(); f.pop();
//        for(int i : a[cur]){
//            c[i] += c[cur]/a[cur].size();
//            f.push(i);
//        }
//    }
    for(int i = 1; i <= n; i++){
        double p = c[i]/a[i].size();
        for(int j : a[i]){
            c[j] += p;
        }
    }

    for(int i = 1; i <= n; i++){
        if(a[i].size() == 0){
            cout<<c[i]<<endl;
        }
    }
}
