#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 10001
#define lc (rt<<1)
#define rc (rt<<1|1)
using namespace std;
int n,q;

struct node{int l, r, sum, lz;} seg[MAXN * 2 + 1];

void push_up(int rt){
    for(int i = 0; i <= n; i++){
        seg[rt].sum = seg[lc].sum + seg[rc].sum;
    }
}

void push_down(int rt){
    int val = seg[rt].lz;
    if(val==0)
        return;
    //cout<<seg[rt].l<<" " << seg[rt].r<<"a"<<endl;
    if(seg[rt].l == seg[rt].r){
        seg[rt].sum += val;
        seg[rt].lz = 0;
    }
    else{
        seg[rt].sum += seg[rt].r-seg[rt].l + 1 * val;
        seg[lc].lz += val;
        seg[rc].lz += val;
        seg[rt].lz = 0;
    }
}

void build(int l, int r, int rt){
    seg[rt].l = l;
    seg[rt].r = r;
    if(l == r) {seg[rt].sum = 0; return;}
    int mid = (l+r) / 2;
    build(1,mid,lc);
    build(mid+1,r,rc);
    seg[rt].sum = 0;//seg[lc].sum + seg[rc].sum;
}

void upd(int l, int r, int val, int rt){
    if(seg[rt].l == l && seg[rt].r == r){
        seg[rt].lz += val;
        return;
    }
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(mid >= r) upd(l,r,val,lc);
    else if(l > mid) upd(l,r,val,rc);
    else{
        upd(l,mid,val,lc);
        upd(mid+1, r, val,rc);
    }
    //push_up(rt);
}

int query(int l, int r, int rt){
    if(seg[rt].l == l && seg[rt].r == r)
        return seg[rt].sum + (seg[rt].lz * (r-l+1));
    if(seg[rt].lz)
        push_down(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(mid >= r) return query(l,r,lc);
    else if(l > mid) return query(l,r,rc);
    else return query(l,mid,lc) + query(mid+1, r, rc);
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    build(1,n,1);
    for(int i = 0,l,r,a; i < q; i++){
        cin>>a;
        if(a==1){
            cin>>l>>r>>a;
            upd(l,r,a,1);
            for(int i = 1; i < n*2+1; i++){
                cout<<seg[i].l<<" " << seg[i].r<< " " << seg[i].sum<<" " << seg[i].lz<< endl;
            }
        }
        else if(a==2){
            for(int i = 1; i < n*2+1; i++){push_down(i);}
            cin>>l>>r;
            cout<<query(l,r,1)<<endl;
        }
    }
    for(int i = 1; i < n*2+1; i++){
        cout<<seg[i].l<<" " << seg[i].r<< " " << seg[i].sum<<" " << seg[i].lz<< endl;
    }





}
