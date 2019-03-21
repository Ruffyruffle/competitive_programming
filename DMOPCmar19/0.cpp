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
int a[4];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 3; i++){
        cin>>a[i];
    }
    for(int j=0;j<3;j++){
        for(int i = 1; i <= 3; i++){
            if(a[a[i]] == 0) a[i]=0;
        }
    } bool t=1;
    for(int i = 1; i <= 3; i++){
        if(a[i]!=0) t=0;
    }
    cout<<(t?"YES":"NO");



}
