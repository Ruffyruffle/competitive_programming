#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
ll n,m;
vector<pii> a;
bool e[MAXN];
int p[MAXN];
double ans = 0, ans2 = 0;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    double d = n*(n-1);
    for(ll i = 1; i <= n; i++){
        if(i%2==1){
            ans+=i*(i-1);
        }
        else{
            ans2+=i*(i-1);
        }
    }
    cout<<d*1/3<<endl<<d*2/3;
}
