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
int n,m,ans,k;
vector<pii> b;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int c=0;
    int a;
    while(n>0){
        a = sqrt(n*2);
        while(a*(a-1) > n*2) a--;
        while(n*2 >= (a+1)*a) a++;
        //cout<<a<<endl;
        for(int i = 1+c; i < a+c; i++){
            b.pb({i,i+1});
        }
        b.pb({1+c,a+c});
        n -= (a*(a-1))>>1;
        c+=a;
//        for(int i = a ; i <= a + r; i+=2){
//            b.pb({i,i+1});
//            b.pb({i+1,i});
//        }
        if(n!=0)b.pb({c,c+1});
    }
    //if(r!=0) b.pb({a+r, 1});
    cout<<c<<" "<<b.size()<<endl;
    for(pii i : b){
        cout<<i.f<<" "<<i.s<<endl;
    }







}
