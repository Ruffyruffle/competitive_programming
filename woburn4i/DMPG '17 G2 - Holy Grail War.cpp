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
#define MAXN 100001
using namespace std;
ll n,m,ans,q;
#define lc rt<<1
#define rc rt<<1|1

struct node{ll l,r,s,ps,ss,ms;}seg[MAXN*4];

void merg(ll rt){
    seg[rt].ps = max(seg[lc].ps, seg[lc].s + seg[rc].ps);
    seg[rt].ss = max(seg[rc].ss, seg[lc].ss+seg[rc].s);
    seg[rt].ms = max(seg[lc].ms, seg[rc].ms);
    seg[rt].ms = max(seg[rt].ms, seg[rt].ps);
    seg[rt].ms = max(seg[rt].ms, seg[rt].ss);
    seg[rt].ms = max(seg[rt].ms, seg[lc].ss+seg[rc].ps);
    seg[rt].s = seg[lc].s+seg[rc].s;
}
void change(ll rt, ll val){
    seg[rt].ps=seg[rt].ss=seg[rt].s=seg[rt].ms=val;
}
void update(ll rt, ll i, ll val){
    if(seg[rt].r==i && seg[rt].l==i) {change(rt, val); return;}
    ll mid = (seg[rt].l+seg[rt].r)>>1;
    if(mid >= i) update(lc, i, val);
    else update(rc,i,val);
    merg(rt);
}
void build(ll l, ll r, ll rt){
    seg[rt].l=l; seg[rt].r=r;
    if(l==r) {cin>>seg[rt].s; change(rt,seg[rt].s); return;}
    ll mid = (l+r)>>1;
    build(l,mid,lc);build(mid+1,r,rc);
    merg(rt);
}
node m2(node a, node b){
    node c;
    c.ps = max(a.ps, a.s + b.ps);
    c.ss = max(b.ss, a.ss+b.s);
    c.ms = max(a.ms, b.ms);
    c.ms = max(c.ms, c.ps);
    c.ms = max(c.ms, c.ss);
    c.ms = max(c.ms, a.ss+b.ps);
    c.s = a.s+b.s;
    return c;
}
node query(ll l, ll r, ll rt){
    if(seg[rt].l == l && seg[rt].r == r) return seg[rt];
    ll mid = (seg[rt].l+seg[rt].r)>>1;
    if(mid >= r) return query(l,r,lc);
    else if(mid < l) return query(l,r,rc);
    else return m2(query(l,mid,lc), query(mid+1,r,rc));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    build(1,n,1);
    ll l,r; char c;
    while(q--){
        cin>>c>>l>>r;
        if(c == 'S'){
            update(1,l,r);
        }
        else cout<<query(l,r,1).ms<<endl;
    }



}
