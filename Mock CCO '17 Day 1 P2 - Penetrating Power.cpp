#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001
typedef long long ll;
ll seg[MAXN<<1];
ll n,h,k,q;
//ll a[MAXN];
ll lz[MAXN];

inline void apply(ll i, ll v){
    seg[i]+=v;
    if(n>i) lz[i]+=v;
}
inline void build(){
    for(ll i = n-1; i > 0; i--) seg[i] = max(seg[i<<1], seg[1<<1|1]);
}
inline void pushup(ll i){
    while(i>1) i>>=1, seg[i] = max(seg[i<<1], seg[i<<1|1]) + lz[i];
}

void pushdown(ll x){
    for(ll s=h;s>0; --s){
        ll i = x>>s;
        if(lz[i]){
            apply(i<<1, lz[i]);
            apply(i<<1|1, lz[i]);
            lz[i] = 0;
        }
    }
}

void rinc(ll l, ll r, ll v){
    if(l>r) return;
    l+=n, r+=n;
    ll l2=l, r2=r;
    for(;r>l;l>>=1,r>>=1){
        if(l&1) apply(l++,v);
        if(r&1) apply(--r, v);
    }
    pushup(l2); pushup(r2-1);
}

ll query(ll l, ll r){
    if(l>r) return 0;
    ll ret = 0;
    l+=n;r+=n;
    for(;r>l; l>>=1, r>>=1){
        pushdown(l); pushdown(r-1);
        if(l&1) ret = max(ret, seg[l++]);
        if(r&1) ret = max(ret, seg[--r]);
    }
    return ret;
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    h = sizeof(ll) * 8 - __builtin_clz(n);
    cin>>n>>k>>q;
    ll c,l,r;
    while(q--){                         `
        cin>>c>>l>>r;
        if(c==0){
            //a[l]+=r;
            rinc(max(0ll,l-k+1), min(n,l+1), r);
//            cout<<endl;
//            for(ll i = 0; i < n; i++){
//                cout<<query(i,i+1)<<endl;
//            }
        }
        else{
            //for(ll i = 0; i < 2*n; i++) pushdown(i);
            cout<<query(max(0ll,l), min(n,r+1))<<endl;
        }
    }
}
/* k=4
0 0 10 0 0 0 0 0
4 0 10 0 0 0 0 0
4 0 10 0 0 0 15 0
Q
4 0 10 6 0 0 15 0
4 3 10 6 0 0 15 0
Q
Q
==
23 19 16 21 15 15 15 0
*/


