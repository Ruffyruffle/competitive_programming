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
#define MAXN 100002
using namespace std;
int n,m; ll ans;
vector<int> a[MAXN];
int s[MAXN],mark[MAXN],par[MAXN],d[MAXN],w[MAXN];

void check(int cur, int last){
    for(int i : a[cur]){
        if(i == last) continue;
        check(i, cur);
        mark[cur] += mark[i];
    }
}

void prop(int cur, int last){
    for(int i : a[cur]){
        if(i == last || mark[i] == 0) continue;
        prop(i, cur);
    }
    int mn = INF;
    if(s[cur] == -1){
        for(int i : a[cur]){
            if(mark[i] == 0) continue;
            mn = min(mn, s[i]);
        }
        s[cur] = mn;
    }
    //cout<<cur<<" "<<s[cur]<<endl;
}

void build(int cur, int last){
    w[cur] = s[cur] - d[par[cur]];
    //cout<<cur<<" "<<par[cur]<< endl;
    ans+=w[cur];
    if(0 > w[cur]){
        cout<<-1;
        exit(0);
    }

    d[cur] = d[par[cur]] + w[cur];
    for(int i : a[cur]){
        if(i == last|| mark[i] == 0) continue;
        build(i,cur);
    }
    //cout<<cur<<" "<<w[cur]<<endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 2,x; i <= n; i++){
        cin>>x;
        a[x].pb(i);
        par[i] = x;
    }
    par[1] = 0;
    w[0] = 0;
    for(int i = 1,x; i <= n; i++){
        cin>>s[i];
        if(s[i] != -1){
            mark[i] = 1;
        }

    }
    mark[1] = 1;
    check(1,0);
    prop(1,0);
    build(1,0);
    cout<<ans;
}
