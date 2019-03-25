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
#define MAXN 1000000
using namespace std;
int n,m,ans,k,c,rr;

int query(int x, int y){
    if(x > rr || y > c) return INF;
    cout<<"? "<<x<<" "<<y<<endl;
    int t; cin>>t;
    return t;
}


int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    cin>>rr>>c>>m;
    int l=1,r=rr,u=1,d=c;
    while(r>=l||d>=u){
        int midx = l+((r-l)/2), midy = u+((d-u)/2);
        //cout<<midx<<" "<<midy<<endl;
        int mq = query(midx,midy), dq = query(midx, midy+1), rq = query(midx+1, midy);

        if(mq > rq) l = midx+1;
        else r = midx-1;

        if(mq > dq) u = midy+1;
        else d = midy-1;
    }
    cout<<"! "<<query(l,u)<<endl;
}
