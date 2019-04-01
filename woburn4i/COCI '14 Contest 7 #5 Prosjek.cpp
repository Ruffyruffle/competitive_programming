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
int n,m,ans;
int a[MAXN];
int tot; bool found,done[MAXN];;

void dfs(int cur, int last){
    if(!done[cur+1]&&cur+1!=last) dfs(cur+1,cur), sz[cur]+=sz[cur+1];
    if(!done[cur-1]&&cur-1!=last) dfs(cur-1,cur), sz[cur]+=sz[cur+1];
}

void cen(int cur, int last){
    if((sz[cur+1]<<1)>=tot&&!done[cur+1]&&cur+1!=last) return cen(cur+1,cur);
    if((sz[cur-1]<<1)>=tot&&!done[cur-1]&&cur-1!=last) return cen(cur-1,cur);
    return cur;
}

void solve(int cur, int last,int v,int l){
    if(v>=0&&l>=k) found=1;
    if(found) return;

    if(!done[cur+1]&&cur+1!=last) dfs(cur+1,cur), sz[cur]+=sz[cur+1];
    if(!done[cur-1]&&cur-1!=last) dfs(cur-1,cur), sz[cur]+=sz[cur+1];
}

void decomp(int rt){
    dfs(rt,-1);
    tot=sz[rt];
    rt=cen(rt,-1);
    done[rt]=1;

    if(found) return;

    if(!done[cur+1]) solve(cur+1,rt);
    if(!done[cur-1]) solve(cur-1,rt);

    if(!done[cur+1]) decomp(cur+1);
    if(!done[cur-1]) decomp(cur-1);
}

bool check(int mid){

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =1; i <= n; i++){
        cin>>a[i];
    }
    double l=0,r=1000000, mid;
    while(r>=l){
        mid=(l+r)>>1;
        if(check(mid)){
            l = mid+0.001;
        }
        else{
            r=mid-0.001;
        }
    }



}
