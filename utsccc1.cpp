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
#define MAXN 1010
using namespace std;
int n,m,q;
vector<int> a[MAXN];
bool v[MAXN];
bool c[MAXN];
bool solve(int x){
    MEM(v,false);
    c[x] = false;
    queue<int> f;
    f.push(1);
    int cur = 1;
    v[cur] = true;
    if(c[1] == false) return false;

    while(!f.empty()){
        cur = f.front();
        f.pop();
        if(cur == n)
            return true;
        for(int i : a[cur]){
            if(c[i] && !v[i]){
                f.push(i); v[i] = true;
            }
        }
    }
    return false;
}

int main(){
    MEM(c,true);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i =0,x,y; i < m; i++){
        cin>>x>>y;
        a[x].pb(y); a[y].pb(x);
    }
    for(int i = 0,x; i < q; i++){
        cin>>x;
        cout<<(solve(x) ? "YES" : "NO")<<endl;
    }
}
