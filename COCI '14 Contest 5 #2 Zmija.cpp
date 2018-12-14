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
#define MAXN 1001
using namespace std;
int r,s, top = INF, cur;
int low[MAXN], high[MAXN];
bool righ = true;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>r>>s;
    char c;
    MEM(low, INF); MEM(high, -1);
    for (int i =1; i <= r; i++){
        for(int j = 1; j <= s; j++){
            cin>>c;
            if(c == 'J'){
                low[i] = min(low[i], j);
                high[i] = max(high[i], j);
                top = min(i, top);
            }
        }
    }
    cur = 1;
    int ans = 0;
    for(int i = r; i >= 1; i--){
        if(low[i-1] == INF && low[i] == INF){
            righ = !righ;
            continue;
        }
        if(righ){
            ans += abs(cur - max(cur,max(high[i], high[i-1])));
            cur = max(cur,max(high[i], high[i-1]));
        }
        else{
            ans += abs(cur - min(cur,min(low[i], low[i-1])));
            cur = min(cur,min(low[i], low[i-1]));
        }
        righ = !righ;
    }
    cout<<(ans + ((top == INF) ? 0 : r-top));
}
