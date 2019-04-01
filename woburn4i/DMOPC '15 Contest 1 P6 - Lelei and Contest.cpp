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
#define MAXN 200001
#define lc rt<<1
#define rc rt<<1|1
#define mid (l+r)>>1
using namespace std;
int n,m,ans,q;
struct node{int l,r,s,lz;}seg[MAXN*3];
void pushup(int rt){seg[rt].s=seg[lc].s+seg[rc].s};
void pushdown(int rt){
    seg[lc].lz+=seg[rt].lz;
    seg[rc].lz+=seg[rt].lz;
    seg[rt].s+=seg[rt].lz*seg[rt].r-seg[rt].l;
    seg[rt].lz=0;
}
void build(int l, int r, int rt){
    seg[rt].l=l;seg[rt].r=r;
    if(l==r){cin>>seg[rt].s;return;}
    build(l,mid,lc); build(mid+1, r, rc);
    pushup(rt);
}
void update(int l,int r,int v, int rt){
    if(seg[rt].l==l&&seg[rt].r==r){
        seg[rt].s+=v*(r-l);
        seg[lc].lz+=v; seg[rc].lz+=v;
    }
    if(seg[rt].lz!=0)pushdown(rt);
    if(mid>=r)update(l,r,v,lc);
    else if(l>mid) update(l,r,v,)


}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n>>q;
    for (int i =0; i < n; i++){

    }



}
