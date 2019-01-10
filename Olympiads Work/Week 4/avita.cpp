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
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 100002
using namespace std;
int n,m,ans,k, co[MAXN];
vector<int> a;
vector<int> par, rk;
vector<int> s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0,x; i < n; i++){
        cin>>x; co[x]++;
    }
    int cur = 0;
    for(int i = 0; i <= n; i++){
        cur++;
        if(co[i] > n-i){
            int t = co[i] / (n-i);
            for(int j = 1; j <= co[i]; j++){
                if(j%t) cur++;
                a.pb(cur);
            }
        }
        else{
            for(int j = 0; j < co[i]; j++){
                a.pb(cur);
            }
        }

    }
    if((cur - a[0] + 1) > n){ cout<<"Impossible"; return 0;}
    for(int i : a){
        cout<<i-a[0]+1<<" ";
    }
}
