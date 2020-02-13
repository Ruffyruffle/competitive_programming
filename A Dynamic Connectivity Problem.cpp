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
#define MAXN 1000000
using namespace std;
int n,m,k;
vector<int> a[MAXN];
vector<int> b,ans;
bool inac[MAXN];
int c[MAXN];
int cur;
bool t[MAXN];
stack<int> changed;
bool color(int cur, int col){
    c[cur] = col;
    for(int i : a[cur]){
        if(c[i] == col||inac[i]) continue;
        color(i,col);
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,y; i < m; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    cin>>k;
    while(k--){
        int x;
        cin>>x;
        b.pb(x); inac[x]=1;
    }
    reverse(b.begin(), b.end());
    for(int i =0; i < n; i++){
        if(c[i]||inac[i]) continue;
        color(i,cur++);
    }
    ans.pb(cur);
    int ans2 = cur;
    for(int i : b){
        inac[i]=0;
        ans2++;
        c[i] = ++cur;
        for(int j : a[i]){
            if(!t[c[j]]) {t[c[j]]=1;
            changed.push(c[j]); ans2--;}
        }
        while(!changed.empty()){
            t[changed.top()]=0;
            changed.pop();
        }
        color(i, c[i]);
        ans.pb(ans2);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }



}
