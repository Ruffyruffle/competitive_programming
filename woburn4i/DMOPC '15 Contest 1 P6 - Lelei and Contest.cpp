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
typedef std::pair<ll, ll> pii;
typedef std::pair<ll, pii> piii;

const ll INF = 0x3f3f3f3f;
#define MAXN 200001
#define lc rt<<1
#define rc rt<<1|1
#define MID ((seg[rt].l+seg[rt].r)>>1)
using namespace std;
ll n,m,ans,q;
struct node{ll l,r,s,lz;}seg[MAXN*4];
void pushup(ll rt){seg[rt].s=seg[lc].s+seg[rc].s; seg[rt].s%=m;}
void pushdown(ll rt){
    seg[lc].lz+=seg[rt].lz;
    seg[rc].lz+=seg[rt].lz;
    seg[lc].s+=seg[rt].lz * (seg[lc].r-seg[lc].l+1);
    seg[rc].s+=seg[rt].lz *(seg[rc].r-seg[rc].l+1);
    seg[rt].lz=0;
}
void build(ll l, ll r, ll rt){
    //cout<<l<<" "<<r<<" "<<rt<<endl;
    seg[rt].l=l;seg[rt].r=r;
    if(l==r){cin>>seg[rt].s;return;}
    build(l,MID,lc); build(MID+1, r, rc);
    pushup(rt);
}
void update(ll l,ll r,ll v, ll rt){
    if(seg[rt].l==l&&seg[rt].r==r){
        seg[rt].s+=v*(r-l+1);
        seg[rt].lz+=v;
        return;
    }
    if(seg[rt].lz)pushdown(rt);
    if(MID>=r)update(l,r,v,lc);
    else if(l>MID) update(l,r,v,rc);
    else{update(l,MID,v,lc); update(MID+1,r,v,rc);}
    pushup(rt);
}
ll query(ll l, ll r, ll rt){
    if(seg[rt].l == l && seg[rt].r ==r) return seg[rt].s;
    if(seg[rt].lz) pushdown(rt);
    if(MID>=r)return query(l,r,lc);
    else if(l>MID)return query(l,r,rc);
    else return query(l,MID,lc) + query(MID+1,r,rc);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n>>q;
    build(1,n,1);
    ll o,x,y,z;
    while(q--){
        cin>>o>>x>>y;
        if(o==1){
            cin>>z;
            update(x,y,z,1);
        }
        else{
            cout<<query(x,y,1)%m<<endl;
        }
    }
}
