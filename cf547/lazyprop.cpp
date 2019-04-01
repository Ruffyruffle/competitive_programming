#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
ll seg[MAXN<<1];
int n,h,k,q;
ll lz[MAXN];

void apply(int i, ll v){
    seg[i]+=v;
    if(n>i) lz[i]+=v;
}

void pushup(int i){
    while(i>1) i>>=1, seg[i] = max(seg[i<<1], seg[i<<1|1]) + lz[i];
}

void pushdown(int x){
    for(int s=h;s>0; --s){
        int i = x>>s;
        if(lz[i]){
            apply(i<<1, lz[i]);
            apply(i<<1|1, lz[i]);
            lz[i] = 0;
        }
    }
}

void rinc(int l, int r, ll v){
    if(l>r) return;
    l+=n, r+=n;
    int l2=l, r2=r;
    for(;r>l;l>>=1,r>>=1){
        if(l&1) apply(l++,v);
        if(r&1) apply(--r, v);
    }
    pushup(l2); pushup(r2-1);
}

ll query(int l, int r){
    if(l>r) return 0;
    ll ret = 0;
    l+=n;r+=n;
    pushdown(l); pushdown(r-1);
    for(;r>l; l>>=1, r>>=1){
        if(l&1) ret = max(ret, seg[l++]);
        if(r&1) ret = max(ret, seg[--r]);
    }
    return ret;
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scan(n);scan(k);scan(q);
    h = sizeof(int) * 8 - __builtin_clz(n);
    int c,l,r;
    while(q--){
        scan(c);scan(l);scan(r);
        if(c==0){
            rinc(max(0,l-k+1), min(n,l+1), r);
//            cout<<endl;
//            for(int i = 0; i < n; i++){
//                cout<<query(i,i+1)<<endl;
//            }
        }
        else{
            //for(int i = 0; i < 2*n; i++) pushdown(i);
            cout<<query(max(0,l), min(n,r+1))<<endl;
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
