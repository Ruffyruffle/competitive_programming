/*
ID: stevenu1
LANG: C++
TASK: gift1
*/

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

const int INF = 0x3f3f3f3f;
#define MAXN 12
using namespace std;
int n, a[MAXN];


int main(){
    freopen ("gift1.in","r",stdin);
    freopen ("gift1.out","w",stdout);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    unordered_map<string,int> in;
    unordered_map<int,string> name;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        in[s] = i;
        name[i] = s;
    }
    int x,y;
    while(cin>>s){
        cin>>x>>y;
        if(y==0) continue;
        int t = x/y;
        a[in[s]] -= x;
        a[in[s]] += x-(t*y);
        for(int i = 0; i < y; i++){
            string ss;
            cin>>ss;
            a[in[ss]]+=t;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<name[i]<< " " <<a[i]<<endl;
    }
    return 0;
}
