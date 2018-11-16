#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 100000
using namespace std;
int w,m;
int seg[MAXN * 2];
int gcd[MAXN * 2];
int cou[MAXN * 2];
int a[MAXN+1];

int Ggcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return Ggcd(b, a%b);
}

void construct(int l, int r, int pos){
    //cout<<l << " " << r << " " << pos << endl;
    if(l==r){
        seg[pos] = a[l];
        gcd[pos] = a[l];
        cou[pos] = 1;
        return;
    }
    int mid = (l+r) / 2;
//    cout<<l << " " << r << " " << pos << endl;
    construct(l, mid, 2*pos+1);

    construct(mid+1, r, 2*pos+2);

    seg[pos] = min(seg[2*pos+1], seg[2*pos+2]);
    gcd[pos] = Ggcd(gcd[2*pos+1], gcd[2*pos+2]);
    cou[pos] = (gcd[pos] == gcd[2*pos+1] ? cou[2*pos+1] : 0) + (gcd[pos] == gcd[2*pos+2] ? cou[2*pos+2] : 0);

}

void update(int l, int r, int pos, int vpos, int val){
    if(vpos < l || vpos>r) return;
    if(l==r){
        seg[pos] = a[l];
        gcd[pos] = a[l];
        a[vpos] = 1;
        return;
    }
    int lc = pos * 2 + 1; int rc = pos * 2 + 2; int mid = (l+r)/2;
    update(l, mid, lc, vpos, val); update(mid+1, r, rc, vpos, val);

    seg[pos] = min(seg[lc], seg[rc]);
    gcd[pos] = Ggcd(gcd[2*pos+1], gcd[2*pos+2]);
    cou[pos] = (gcd[pos] == gcd[2*pos+1] ? gcd[2*pos+1] : 0) + (gcd[pos] == gcd[2*pos+2] ? gcd[2*pos+2] : 0);
}

int rangemin(int ql, int qr, int l, int r, int pos){
    if(ql <= l && qr >=r){
        return seg[pos];
    }
    if(ql > r || qr < l){
        return INF;
    }
    int mid = (l+r) / 2;
    return min(rangemin(ql,qr,l,mid,2*pos+1), rangemin(ql,qr,mid+1,r,2*pos+2));
}

int rangegcd(int ql, int qr, int l, int r, int pos){
    if(ql <= l && qr >=r){
        return gcd[pos];
    }
    if(ql > r || qr < l){
        return -1;
    }
    int mid = (l+r) / 2;
    return Ggcd(rangegcd(ql,qr,l,mid,2*pos+1), rangegcd(ql,qr,mid+1,r,2*pos+2));
}

int rangecount(int ql, int qr, int l, int r, int pos){
    if(ql <= l && qr >=r){
        return cou[pos];
    }
    if(ql > r || qr < l){
        return -1;
    }
    int mid = (l+r) / 2;
    int gc = rangegcd(ql,qr, l, r, pos);
    int cou = (gc == rangegcd(ql,qr,l,mid,2*pos+1) ? rangecount(ql,qr,l,mid,2*pos+1) : 0 )+( (rangegcd(ql,qr,mid+1,r,2*pos+2)) ? rangecount(ql,qr,l,mid,2*pos+2) : 0);
}

int main(){
    cin>>w>>m;
    for (int i = 0; i < w; i++){
        cin>>a[i];
    }
    w--;
    construct(0,w,0);
//    for(int i = 0; i < 20; i++){
//        cout<<seg[i] << endl;
//    }
    char c; int x,y;
    for(int i = 0; i < m; i++){
        cin>>c>>x>>y;
        if(c == 'C'){
            update(0,w,0,x,y);
        }
        else if(c == 'M'){
            cout<<rangemin(x,y, 0, w, 0)<<endl;
        }
        else if (c == 'G'){
            cout<<rangegcd(x,y, 0, w, 0)<<endl;
        }
        else if(c == 'Q'){
            cout<<rangecount(x,y, 0, w, 0)<<endl;
        }

    }


}
