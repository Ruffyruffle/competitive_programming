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
ll n,m,ans,k,x;
ll sum, mx, avg, pt,pt2;
vector<int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    cout<<fixed<<setprecision(6);
    for (int i =0; i < n; i++){
        cin>>x;
        a.pb(x);
        sum+=x;
    }
    pt2 = n-1;
    sort(a.begin(), a.end());

    if(m > n){
        cout<<a[n-1] + min(k,max(0ll,m-(n-1)));
        return 0;
    }
    else{
        while(m!=0){
            if(n-1 > pt && a[n-1] - (n-pt) >= a[pt]){
                sum-=a[pt];
                pt++; m--;
            }
            else{
                a[pt2] += (min(m,k));
                if(pt2 >= pt) sum+=min(m,k);
                m-=min(m,k);
                pt2--;
            }
        }
    }
    cout<<sum/(n-pt);



}
