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
#define MAXN 500001
using namespace std;
int n,m,ans;
int a[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    for (int i =0,x; i < n; i++){
        cin>>x;
        a[x]++;
        if(a[x] == 1){
            ans++;
        }
    }
    int t,ans2=0;
    if(ans > m){
        sort(a+1, a+n+1);
        int start = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                start = i; break;
            }
        }
        for(int i = start; i < start+ans-m; i++){
            ans2+=a[i];
        }
        cout<<ans2;
    }
//    for(int i = 1; i <=n; i++){
//        if(a[i] == 1)
//            ans++;
//    }
    else cout<<abs(m-ans);



}
