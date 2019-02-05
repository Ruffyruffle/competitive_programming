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
#define MAXN 1001
using namespace std;
int n,q,k,c,x,y, root = 1;
ll ans;
vector<int> a[MAXN];
int v[MAXN];

int sum(int cur, int dest, int last = -1, ll ret = 0){
    ret+=v[cur];
    for(int i : a[cur]){
        if(i==last) continue;
        sum(i,dest,cur,ret);
    }
    if(cur == dest)
        ans = ret;
    return ans;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q>>k;
    for (int i =1; i <= n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < n-1; i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    while(q--){
        cin>>c;
        if(c==1) cin>>root;
        else{
            cin>>x>>y;
            ans = 0;
            switch(c){
                case 2: cout<<root;
                case 3: cout<<sum(x,y);
//                case 4: cout<<product(x,y);
//                case 5: cout<<mn(x,y);
//                case 6: cout<<mx(x,y);
//                case 7: cout<<gcd(x,y);
//                case 8: cout<<bitAND(x,y);
//                case 9: cout<<bitOR(x,y);
//                case 10: cout<<bitXOR(x,y);
//                case 11: cout<<great(x,y):
//                case 12: cout<<small(x,y);
//                    break;
//                case 13:
//                    break;
//                case 14:
//                    break;
            }
            cout<<endl;
        }
    }



}
