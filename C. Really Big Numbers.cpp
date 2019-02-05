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
typedef std::pair<ll, ll> pii;
typedef std::pair<ll, pii> piii;

const ll INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ll n,m,ans;

ll sum(ll x){
    ll ret=0;
    while(x>0){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
bool solve(ll x){
    return x-sum(x)>=m;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll l=0,r=n,mid;
    while(r>=l){
        mid = (l+r)/2;
        if(solve(mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<n-l+1;



}
