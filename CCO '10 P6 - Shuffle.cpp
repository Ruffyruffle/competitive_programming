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
int n,m,ans,k;
int a[28];
int b[28];
bool vis[28];
int dfs(int cur, int x){
    //assert(26>=cur&&cur>=0);
    if(vis[cur]) return x;
    vis[cur]=1;
    return dfs(a[cur],x+1);
}
int dfs2(int cur, int x){
    if(x==0) return cur;
    return dfs2(a[cur],x-1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);string x;
    for(int i =0;i<27;i++){
        cin>>x; if(x[0] == '_') a[i]=26;
                else a[i]=x[0]-'A';
    }
    string s;
    cin>>n>>s;
    for(int i=0;i<27;i++){
        MEM(vis,0);
        int c = dfs(i,0);
        b[i] = dfs2(i,n%c);
        //cout<<c<<" "<<n%c<<endl;
        if(b[i] == 26) b[i] = 30;
    }
    //cout<<a[1];
    //cout<<(int)('_'-'A')<<endl;
    for(char i : s){
        if(i == '_') i = (char)('Z'+1);
        cout<<(char)(b[i-'A']+'A');
    }







}
