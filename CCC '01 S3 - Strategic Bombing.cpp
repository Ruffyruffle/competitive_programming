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
#define MAXN 26
using namespace std;
int n,m; bool vis[MAXN];
int low[MAXN], num[MAXN];
int ti;
vector<int> a[MAXN]; vector<pii> ans;

void dfs(int cur, int last = -1){
    vis[cur] = 1;
    num[cur] = low[cur] = ti++;
    for(int i : a[cur]){
        if(last == i) continue;
        if(vis[i]) low[cur] = min(low[cur], num[i]);
        else{
            dfs(i,cur);
            low[cur] = min(low[cur], low[i]);
            if(low[i] > num[cur]) ans.pb({cur, i});
        }
    }

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0); string s = "";
    while(s!="**"){
        cin>>s;
        if(s!="**"){
            a[s[0]-'A'].pb(s[1]-'A');
            a[s[1]-'A'].pb(s[0]-'A');
        }
    }
    dfs(0);
    for(pii i : ans){
        cout<<(char)(i.f+'A')<<(char)(i.s+'A')<<endl;
    }
    cout<<"There are "<<ans.size()<<" disconnecting roads.";



}
