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
int dir[4]; //u,d,l,r
int a[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x,y,x2,y2;
    cin>>x>>y>>x2>>y2;
    cin>>n; char xx;
    for (int i =0; i < n; i++){
        cin>>xx;
        if(xx == 'U'){
            dir[0]++; a[i] = 0;
        }else if (xx == 'D'){
            dir[1]++; a[i] = 1;
        }else if (xx == 'L'){
            dir[2]++; a[i] = 2;
        }else if (xx == 'R'){
            dir[3]++; a[i] = 3;
        }
    }
    int m = abs(x-x2) + abs(y-y2);
    for(int i = 0; i < 4; i++){
        dir[i]*= floor(m/n);
    }
    for(int i = 0; i < m%n; i++){
        dir[a[i]]++;
    }
    if(x>x2){
        ans += max(0, x-x2-dir[2] + dir[3]);
    }
    else{
        ans += max(0, x2-x-dir[3] + dir[2]);
    }
    if(y>y2){
        ans += max(0, y-y2-dir[1] + dir[0]);
    }
    else{
        ans+= max(0,y2-y-dir[0] + dir[1]);
    }
    ans = max(ans, min(abs(x2-x), abs(y2-y)));
    if(ans > m) cout<<-1;
    else cout<<ans;



}
