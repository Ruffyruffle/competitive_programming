#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000010
#define lc (rt<<1)
#define rc (rt<<1|1)
#define cmid (seg[rt].l + seg[rt].r)>>1;
using namespace std;
int n,q;

struct node{int l,r,sum,lzv,lzl,mid;} seg[MAXN*3];

void push_down(int rt){
    if(seg[rt].lzv == 0) return;
    int val = seg[rt].lzv;
    int start = seg[rt].lzl;

    if(seg[rt].l == seg[rt].r){
        seg[rt].sum += (seg[rt].r - start + 1) * val <<1;
        seg[rt].lzv = seg[rt].lzl = 0;
    }
    else{
        if(seg[lc].lzl == seg[rt].lzl)
            seg[lc].lzv += seg[rt].lzv;
        else{
            push_down(lc);
            seg[lc].lzl = start;
            seg[lc].lzv = val;
        }

        if(seg[rc].lzl == seg[rt].lzl)
            seg[rc].lzv += seg[rt].lzv;
        else{
            push_down(rc);
            seg[rc].lzl = start;
            seg[rc].lzv = val;
        }
        seg[rt].lzv = seg[rt].lzl = 0;
        seg[rt].sum += (seg[rt].r - seg[rt].l + 1) * (((seg[rt].l - start + 1) * val) + ((seg[rt].r - start + 1) * val));
    }
}

void build(int l, int r, int rt){
    seg[rt].l = l;
    seg[rt].r = r;
    if(l==r) return;
    seg[rt].mid = cmid;
    build(l,seg[rt].mid,lc);
    build(seg[rt].mid+1, r, rc);
    seg[rt].lzv = seg[rt].lzl = 0;
}

void update(int l, int r, int rt, int start, int val){
    if(seg[rt].l == l && seg[rt].r == r){
        if(seg[rt].lzl == start)
            seg[rt].lzv += val;
        else{
            push_down(rt);
            seg[rt].lzl = start;
            seg[rt].lzv = val;
        }
        return;
    }
    else if(seg[rt].l <= l && seg[rt].r>= r){
        seg[rt].sum += (r - l + 1) * (((l - start + 1) * val) + ((r - start + 1) * val));
        //cout<<"a";
    }
    else if(seg[rt].l <= l){
        seg[rt].sum += (seg[rt].r - l + 1) * (((l - start + 1) * val) + ((seg[rt].r - start + 1) * val));
    }
    else if(seg[rt].r >= r){
        seg[rt].sum += (r - seg[rt].l + 1) * (((seg[rt].l - start + 1) * val) + ((r - start + 1) * val));
    }

    if(seg[rt].mid >= r)
        update(l,r,lc,start,val);
    else if(l > seg[rt].mid)
        update(l,r,rc,start,val);
    else{
        update(l,seg[rt].mid,lc,start,val);
        update(seg[rt].mid+1, r, rc, start,val);
    }
    //push_up();
}

int sum(int l, int r, int rt){
    push_down(rt);
    if(seg[rt].l == l && seg[rt].r == r)
        return seg[rt].sum;
    if(seg[rt].mid>=r)
        return sum(l,r,lc);
    else if(l>seg[rt].mid)
        return sum(l,r,rc);
    else
        return (sum(l,seg[rt].mid,lc) + sum(seg[rt].mid+1,r,rc));
}

int main(){
    cin.sync_with_stdio(0);
    cout.tie(0);
    scan(n); scan(q);
    build(1,n,1);
    for(int i = 0,x,y,v,c; i < q; i++){
        scan(c);
        if(c == 1){
            scan(x); scan(y); scan(v);
            update(x,y,1,x,v);
        }
        if(c == 2){
            scan(x); scan(y);
            cout<<(sum(x,y,1)>>1)<<'\n';
        }
    }
}
/*
4 5
1 1 4 2
1 1 3 1
2 1 1
2 1 2
2 2 4
*/
