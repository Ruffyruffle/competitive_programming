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
int n,m,t; ll ans;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    bool asc = 1, dec = 1, con = 1;
    int last; cin>>last;
    for (int i =0,x,y; i < 3; i++){
        cin>>x;
        if(x==last){
            asc=0;dec=0;
        } if(x > last){
            dec = 0; con = 0;
        } if(last > x){
            asc = 0; con = 0;
        }
        last = x;
    }
    if(asc){
        cout<<"Fish Rising";
    }else if (con){
        cout<<"Fish At Constant Depth";
    }else if(dec){
        cout<<"Fish Diving";
    }else cout<<"No Fish";


}
