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
string s;
int psa[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s;
    for(int i = 1; i <= s.length();i++){
        psa[i] = psa[i-1] + (s[i-1] == 'G' ? 1 : 0);
    }
    int q; cin>>q;
    for(int i = 0,x,y; i < q; i++){
        cin>>x>>y;
        cout<<psa[y+1] - psa[x]<<endl;
    }
}
