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
int n,m,ans;
int a[MAXN];
vector<int> b;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0; i < n; i++){
        cin>>a[i];
        bool n=0;
        for(int &x : b){
            if(a[i]==x)n=1;
        }
        if(!n && b.size() == 3) {cout<<-1;return 0;}
        else if(!n) b.pb(a[i]);
    }
    sort(b.begin(), b.end());
    if(b.size() == 1) cout<<0;
    else if(b.size() == 2) cout<<((b[1]-b[0])%2==0?(b[1]-b[0])/2:b[1]-b[0]);
    else if(b.size() == 3){
        if(b[2] - b[1] == b[1] - b[0]){
            cout<<b[2]-b[1];
        }
        else cout<<-1;
    }



}
