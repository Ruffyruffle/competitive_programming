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

const ll INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 200005
using namespace std;
ll n,m,ans=INF;
ll a[MAXN], rtot;
ll ptot[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>m>>n;
    ll t =0, mt=INF;
    for (int i =0; i < n; i++){
        cin>>a[i];
        rtot+=a[i];
        t+=a[i];
        ptot[i] = t;
        mt=min(t,mt);
    }
    if(rtot>=0 && m>abs(mt)){
        cout<<-1;
        return 0;
    }
    //cout<<ans<<endl;
    for(int i = 0; i < n; i++){
        ll p = m+ptot[i];
        if(0>=p){
            cout<<i+1; return 0;
        }
        else{
            ll tans = p/rtot;
            tans = abs(tans);
            if(p%rtot != 0) tans++;
            tans*=n;
            tans+=i+1;
            tans=abs(tans);
            //cout<<tans<<endl;
            ans = min(ans, tans);
        }
    }
//    ll tans = m/rtot;
//    tans=abs(ans);
//    if(m%rtot != 0) tans++;
//    tans*=n;
//    ans=min(ans,tans);


    cout<<ans;

//    int tt=0;
//    while(1){
//        for(int i = 0; i < n; i++){
//            m+=a[i];
//            tt++;
//            if(0>=m){
//                cout<<tt; return 0;
//            }
//        }
//    }



}
