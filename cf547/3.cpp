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
#define MAXN 200010
using namespace std;
int n,m,ans;
int c2[MAXN*2];
int a[MAXN];
int f[MAXN*2];
bool fr[MAXN*2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0; i < n-1; i++){
        cin>>a[i];
    }
    int cur = MAXN-5;
    f[0] = cur;
    for(int i = 0; i < n-1; i++){
        cur+=a[i];
        if(c2[cur]){
            cout<<-1; return 0;
        }
        else {f[i+1] = cur; c2[cur]=1;}
    }
    int mx = INF;
    for(int i = 0; i < n; i++){
        mx = min(f[i], mx);
    } mx--;
    for(int i = 0; i < n; i++){
        f[i]-=mx;
        if(fr[f[i]] == 0 && f[i] <= n){
            fr[f[i]]=1;
        }
        else{
            cout<<-1; return 0;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<f[i]<<" ";
    }



}
