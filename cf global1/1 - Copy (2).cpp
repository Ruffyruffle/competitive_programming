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
#define MAXN 100001
using namespace std;
ll n,m,ans,k; int a[MAXN];
vector<pii> dif;
vector<int> start;
vector<int> c;
bool cmp(pii a, pii b){
    return b.f < a.f;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i =1,x; i <= n; i++){
        cin>>a[i];
        c.pb(-a[i]);
    }
    for(int i = 2; i <=n; i++){
        dif.pb({a[i]-a[i-1], a[i]});
    }
    sort(dif.begin(),dif.end(),cmp);
    ans+=k;
    k--;
    start.pb(a[1]);
    for(int i = 0; i < k; i++){
        start.pb(dif[i].s);
    }
     //int p = 0;

//    for(int i : start){
//        cout<<i<<endl;
//    }
//    for(int i : c){
//        cout<<i<<endl;
//    }
    sort(c.begin(),c.end());
    for(int i = start.size()-1; i >=1; i--){
        //cout<<-start[i]<<endl;
        //cout<<-*upper_bound(c.begin(), c.end(), -start[i])<<endl;
        ans+= -*upper_bound(c.begin(), c.end(), -start[i]) - start[i-1];
    }
    ans+=a[n] - start[start.size()-1];

//    for(int i = 1; i <= n; i++){
//        //cout<<a[i] << " "<< start[p];
//        if(p == start.size()-1){
//            ans+= a[n] - start[p];
//            //cout<<start[p]<<" "<<a[n]<<endl; break;
//        }
//        if(a[i] == start[p]){
//            cout<<start[p]<<" "<<a[i]<<endl;
//            ans+= a[i+1] - start[p-1];
//            p++;
//        }
//    }
    cout<<ans;




}
