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
#define MAXN 1000000
using namespace std;
int n,m,ans = -1;
vector<int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        cin>>x; a.pb(x);
    }
    int b = 0, c = 0,ans2 = 0;;
    for(int i = n-1; i >= 0; i--){
        if(a[i] != 0){
            b = a[i];
        }
        else if(a[i] <= 0)
            b--;
            if(b<=1)
                ans++;

    }
    b = 0;
    for(int i = 0; i < n; i++){
        b++;
        if(a[i] != 0){
            if(b>a[i]){
                ans2++;
            }
            else if(a[i] > b){
                cout<<-1;
                return 0;
            }
            b = a[i];
        }
    }
    cout<<ans2<<" " <<ans;
}
