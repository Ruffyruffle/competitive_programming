#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000010
using namespace std;
ll n,q;
ll bit[MAXN];

void add(int i, int v){
    while(i<= MAXN){
        bit[i]+=v;
        i+=(-i&i);
    }
}
ll sum(int i){
    ll ans = 0;
    while(i>0){
        ans+=bit[i];
        i-= (i&-i);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);scan(q);
    unordered_map<ll, int> o;
    vector<ll> s;
    vector<ll> f;

    for (ll i =1,x; i <= n; i++){
        scan(x);
        o[x] = i;
        s.pb(x);
        f.pb(-x);
    }
    int c;
    for(ll i = 0,x,y,v; i < q; i++){
        scan(c);
        if(c==1){
            scan(x); scan(y); scan(v);
            add(o[*lower_bound(s.begin(), s.end(), x)], v);
            add(o[*--upper_bound(s.begin(), s.end(), y)]+1, -v);
        }
        else{
            scan(x);
            cout<<sum(x)<<'\n';
        }
    }
}
//#include <bits/stdc++.h>
//
//#define MEM(a, b) memset(a, (b), sizeof(a))
//#define PI 3.1415926535897932384626433832795
//#define endl '\n'
//#define exists(s, e) (s.find(e)!=s.end())
//#define WHILE(n)
//#define pb push_back
//#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
//char _;
//typedef long long ll;
//typedef long double ld;
//typedef std::pair<int, int> pii;
//
//const int INF = 0x3f3f3f3f;
//#define MAXN 1000010
//#define lc (rt<<1)
//#define rc (rt<<1|1)
//#define cmid (seg[rt].l + seg[rt].r)>>1;
//using namespace std;
//int n,q;
//
//struct node{int l, r, sum, lz, mid;} seg[MAXN * 4];
//
//void push_down(int rt){
//    if(seg[rt].lz == 0) return;
//    int val = seg[rt].lz;
//
//    if(seg[rt].l == seg[rt].r){
//        seg[rt].sum += val;
//        seg[rt].lz = 0;
//    }
//    else{
//        seg[rt].sum += (seg[rt].r-seg[rt].l + 1) * val;
//        seg[lc].lz += val;
//        seg[rc].lz += val;
//        seg[rt].lz = 0;
//    }
//}
//
//void build(int l, int r, int rt){
//    seg[rt].l = l;
//    seg[rt].r = r;
//    if(l==r) return;
//    seg[rt].mid = cmid;
//    build(l,seg[rt].mid,lc);
//    build(seg[rt].mid+1, r, rc);
//    seg[rt].lz = 0;
//}
//
//void upd(int l, int r, int val, int rt){
//    if(seg[rt].l == l && seg[rt].r == r){
//        seg[rt].lz += val;
//        return;
//    }
//    else if(seg[rt].l <= l && seg[rt].r>= r){
//        seg[rt].sum += (r - l + 1) * val;
//    }
//    else if(seg[rt].l <= l){
//        seg[rt].sum += (seg[rt].r - l + 1) * val;
//    }
//    else if(seg[rt].r >= r){
//        seg[rt].sum += (r - seg[rt].l + 1) * val;
//    }
//    if(seg[rt].mid >= r) upd(l,r,val,lc);
//    else if(l > seg[rt].mid) upd(l,r,val,rc);
//    else{
//        upd(l,seg[rt].mid,val,lc);
//        upd(seg[rt].mid+1, r, val,rc);
//    }
//}
//
//int query(int l, int r, int rt){
//    push_down(rt);
//    if(seg[rt].l == l && seg[rt].r == r)
//        return seg[rt].sum;
//    if(seg[rt].mid>=r)
//        return query(l,r,lc);
//    else if(l>seg[rt].mid)
//        return query(l,r,rc);
//}
//
//
//int main(){
//    cin.sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    scan(n); scan(q);
//    build(1,n,1);
//    unordered_map<ll, int> o;
//    for (ll i =1,x; i <= n; i++){
//        scan(x);
//        o[x] = i;
//    }
//    int c;
//    for(ll i = 0,x,y,v; i < q; i++){
//        scan(c);
//        if(c==1){
//            scan(x); scan(y); scan(v);
//            x = o[x]; y = o[y];
//            upd(x,y,v,1);
//        }
//        else{
//            scan(x);
//            cout<<query(x,x,1)<<endl;
//        }
//    }
//}
