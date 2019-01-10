#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<double, double> pii;
typedef std::pair<double, pii> piii;

const double INF = 0x3f3f3f3f;
#define MAXN 300001
using namespace std;
int n,m,ans,d;
int a[MAXN];ll tot = 0;
int bit[MAXN];


void add(int i, int val){
    while(i <= MAXN){
        bit[i]+=val;
        i+=(i&-i);
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i-=(i&-i);
    }
    return ans;
}


int solve(){
    vector<int> b;
    for(int i =1; i <= n; i++){
        b.pb(a[i]);

    }
    sort(b.begin(),b.begin()+n);
    reverse(b.begin(), b.end());
    ll dv = 0, di = 0;
    while(dv <= tot/2){
        dv+=b[di];
        di++;
    }
    return di;

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>d;

    for(int i = 1,x; i <=n; i++){
        cin>>a[i];
        tot+=a[i];
    }
    cout<<solve()<<endl;
    for(int i = 0,x,y; i < d; i++){
        cin>>x>>y;
        tot+=(y-a[x]);
        add(x,y-a[x]);
        a[x] = y;
        cout<<solve()<<endl;
    }
}

