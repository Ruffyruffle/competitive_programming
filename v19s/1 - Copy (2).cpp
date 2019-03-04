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
#define MAXN 100002
using namespace std;
int n,m,ans;
bool fr[MAXN],fc[MAXN];
unordered_map<ll,int> cac;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0,x,r,c; i < m; i++){
        cin>>x>>r>>c;
        if(x==1){
            cac[r*(n+1)+c] = !cac[r*(n+1)+c];
            fr[r] = !fr[r]; fc[c] = !fc[c];
        }
        if(x==2){
            bool ret = cac[r*(n+1)+c];
            if(fr[r]) ret = !ret;
            if(fc[c]) ret = !ret;
            cout<<ret<<endl;
        }
    }



}
