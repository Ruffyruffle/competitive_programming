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


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b,c,d;char f;
    cin>>a>>f>>b>>c>>f>>d;
//    int delta = ((c-a)*60)>>1;
//    delta+=(d-b)>>1;
//    if(10 > a+delta/60) cout<<0;
//    cout<<a+delta/60<<':';
//    if(10>b+(delta%60)) cout<<0;
//    cout<<b+(delta%60);
    a = a*60 + b;
    c = c*60 + d;
    a = (a+c)/2;
    if(10>a/60) cout<<0;
    cout<<a/60<<':';
    if(10>a%60) cout<<0;
    cout<<(a%60);




}
