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
#define MAXN 5001
using namespace std;
int n,s,ans,bgn,num;
vector<int> a[MAXN];
int d[MAXN], mrk[MAXN], par[MAXN], node[MAXN];

//int dfs(int cur, int last, int i){
//    int cv = INF;
//    for(int ne : a[cur]){
//        if(ne == last) continue;
//        cv = min(cv, dfs(ne,cur,i)) - 1;
//    }
//    if(a[cur].size() == 1){
//        cv = i-1;
//    }
//    if(cv == 0){
//        mrk[cur] = 1;
//        cv = (i-1)*2;
//        num++;
//    }
//    //cout<<cur<<" "<<cv<<endl;
//    return cv;
//}
void dfs(int cur, int last, int d){
    if(0> d) return;
    mrk[cur] = 1;
    for(int i : a[cur]){
        if(i==last) continue;
        dfs(i,cur,d-1);
    }
}

bool solve(int i){
    MEM(mrk,0);
    num = 0;
    //for(int c : node){
    for(int k = 1; k <= n; k++){
        //if(c==0) continue;
        int c = node[k];
        if(mrk[c]) continue;
        if(num > s) return 0;
        int t = c;
        for(int j = 0; j < i; j++){
            //cout<<t<<endl;
            if(par[t] == -1) break;
            t = par[t];
        }
        dfs(t, -1, i);
        num++;
    }
//    mrk[bgn] = i;
//    num = 0;
//    //cout<<i<<endl;
//    dfs(bgn,-1,i);
//    //cout<<dfs(bgn,-1,i)<<endl;
    return (num <= s);
}

int dfss(int cur, int last){
    par[cur] = last;
    for(int i : a[cur]){
        if(i==last) continue;
        d[i] = d[cur] + 1;
        dfss(i,cur);
    }
}
bool cmp(int a, int b){return d[a] > d[b];}
int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i =1,x,y; i <= n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        node[i] = i;
    }
    node[n] = n;
    dfss(1,-1);
    sort(node+1, node+n+1,cmp);
//    for(int i = 1; i <= n; i++){
//        if(d[i] > ans){
//            ans = d[i];
//            bgn = i;
//        }
//    }
//    ans = INF;
    int l = 0, r = n,mid;
    while(l <= r){
        mid = (l+r)/2;
        if(solve(mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<l;



}
