#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 200001
using namespace std;
int n,q;
vector<pii> a;
ll bit[MAXN];
ll ans[MAXN];

void add(ll i, ll val){
    while(i<=MAXN){
        bit[i]+=val;
        i+= i&-i;
    }
}

ll sum(ll i){
    ll ans = 0;
    while(i > 0){
        ans+=bit[i];
        i-= i&-i;
    }
    return ans;
}

struct query{
    int l,r,k,i;
};

bool cmp(query a, query b){ return a.k > b.k; }

vector<query> qes;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    //int s = 0;
    cin>>n>>q;
    ll x;
    for(int i = 0; i < n; i++){
        cin>>x;
        a.pb({x,i});
        add(i+1, -x);
    }
    for(int i = 0,l,r,k; i < q; i++){
        cin>>l>>r>>k;
//        ll ans = 0;
//        for(int j = l; j <= r; j++){
//            if(a[j-1] >= k)
//                ans+=a[j-1];
//            else
//                ans-=a[j-1];
//        }
//        cout<<ans<<endl;
        qes.pb({l,r,k,i});
    }
    sort(qes.begin(), qes.end(), cmp);
    sort(a.begin(), a.end());
    int curp = n-1;
    for(query i : qes){
        while(1){
            if(a[curp].f >= i.k){
                if(curp == -1)
                    break;
                add(a[curp].s + 1, 2 * a[curp].f);
                curp--;
            }
            else{
                break;
            }
        }
        ans[i.i] = (sum(i.r) - sum(i.l-1));
    }
    for(int i = 0; i < q; i++){
        cout<<ans[i]<<endl;
    }
}


