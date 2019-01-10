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
#define MAXN 100001
using namespace std;
int m,ans,q,c,d,e;
bool pr[MAXN];
vector<int> a;


bool solve(int n){
    if(n<=1) return false;
    if(pr[n])
        return false;
    int b =0,t=n;
    while(t>0){
        b+=t%10;
        t/=10;
   }
   if(pr[b])
       return false;

   return true;
}

int main(){
    int n;
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int ans = 0;
    for(int i = 2; i*i <= MAXN; i++){
        if(!pr[i]){
            for(int j = i*2; j<=MAXN; j+=i){
                pr[j] = 1;
            }
        }
    }
    for(int i =0,x;i <n; i++){
        cin>>x;
        if(solve(x)) ans++;
    }
    cout<<ans;
}
