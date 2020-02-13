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
#define MAXN 200001
using namespace std;
int n,m,ans,q;
vector<int> a;
int pos[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i =0,x; i < n; i++){
        cin>>x;
        a.pb(x);
        pos[x] = i;
    }
    char c;
    int x,y,z;;
    int last=0;
    while(q--){
        cin>>c;
        if(c == 'I'){
            cin>>x>>y;
            x^=last;
            y^=last;
            if(x == a.size()) a.pb(y);
            else if (x == 0) a.insert(a.begin(),y);
            else a.insert(a.begin()+x, y);
        }
        else if(c == 'D'){
            cin>>x;x^=last;x--;

            a.erase(a.begin()+x);
        }
        else{
            cin>>x>>y>>z;
            x^=last;
            y^=last;
            z^=last;x--;y--;
            ans = 0;
            for(int i =x; i <= y; i++){
                if(a[i] == z) ans++;
            }
            cout<<ans<<endl;
            last = ans;
        }
    }


}
