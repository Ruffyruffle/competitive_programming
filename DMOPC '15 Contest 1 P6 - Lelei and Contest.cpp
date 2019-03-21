#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long ll;
ll n,m,q,h;
ll s[MAXN<<1], lz[MAXN];

inline void apply(ll i, ll v, ll k){
    s[i]+=v*k;
    if(n>i)lz[i]+=v;
}
void calc(int i, int k){
    if(lz[i]==0)s[i] = s[i<<1] + s[1<<1|1];
    else s[i] = lz[i]*k;
}
void build(){
    int k=2,l=0,r=n;
    for(l+=n, r+=n-1; l>1; k<<=1){
        l>>=1,r>>=1;
        for(int i = r; i >= l; i--) calc(i,k);
    }
}
void pushup(ll i, int k){
    while(i>1) i>>=1, s[i] = s[i<<1] + s[i<<1|1];
}
void pushdown(ll x, int k){
    for(ll l = h, k=1<<(h-1); l > 0; l--, k>>=1){
        ll i = x>>l;
        if(lz[i]){
            apply(i<<1, lz[i],k);
            apply(i<<1|1, lz[i],k);
            lz[i]=0;
        }
    }
}
void rinc(ll l, ll r, ll v){
    l+=n, r+=n;
    ll l2 = l, r2 = r;
    for(;r>l;l>>=1,r>>=1){
        if(l&1) apply(l++,v);
        if(r&1) apply(--r,v);
    }
    pushup(l2);pushup(r2-1);
}
ll query(ll l, ll r){
    ll ret=0;
    l+=n, r+=n;
    pushdown(l);pushdown(r-1);
    for(;r>l;l>>=1,r>>=1){
        if(l&1) ret+=s[l++];
        if(r&1) ret+=s[--r];
    }
    return ret;
}



int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>n>>q;
    h = sizeof(int) * 8 - __builtin_clz(n);
    for(ll i = 0; i < n; i++){
        cin>>s[i+n];
    }
    build();
    ll c,l,r,x;
    while(q--){
        cin>>c>>l>>r;
        if(c==1){
            cin>>x;
            rinc(l-1,r,x);
        }
        else{
            cout<<(query(l-1,r)%m)<<endl;
        }
    }


}
