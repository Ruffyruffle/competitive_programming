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
int n,m,co[7];
vector<pair<int,pii>> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y,z; i < n; i++){
        cin>>x>>y>>z;
        a.pb({x,{abs(y), abs(z)}});
    }
    cin>>m;
    string s;
    //o,v,n,ov,vn,on,ovn
    for(int i = 0; i < m; i++){
        cin>>s;
        if(s=="O")

    }
    for(pair<int,pii> i : a){
        if(co[0] >= i.f && co[1] >= i.s.f && co[2] >= i.s.s)
            cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
}
