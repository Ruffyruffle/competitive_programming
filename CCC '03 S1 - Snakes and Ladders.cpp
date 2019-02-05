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
pii a[] = {{54,19},{90,48},{99,77},{9,34},{40,64},{67, 86}};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0); int cur = 1;
    while(cin>>n){
        if(n == 0){cout<<"You Quit!"; return 0;}
        cur+=n;
        for(pii i : a){
            if(cur == i.f) cur = i.s;
        }
        if(cur > 100) cur-=n;
        cout<<"You are now on square "<<cur<<endl;
        if(cur == 100){
            cout<<"You Win!"<<endl; return 0;
        }
    }



}
