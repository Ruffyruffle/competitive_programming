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
typedef std::pair<int, pii> piii;
const int INF = 0x3f3f3f3f;
#define MAXN 1001
using namespace std;
int n,k;
vector<int> par, rk;
vector<piii> a;

void init(){
    for(int i = 1; i <= MAXN; i++){
        par[i] = i;
        rk[i] = 0;
    }
}

int fnd(int i){
    if(par[i] == i) return i;
    return par[i] = fnd(par[i]);
}

bool onion(int a, int b){
    a = fnd(a); b = fnd(b);
    if(a==b) return false;
    if(rk[b]>rk[a])
        swap(a,b);
    par[b] = a;
    if(rk[a] == rk[b])
        rk[a]++;
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rk.resize(MAXN); par.resize(MAXN);
    init();
    for (int i =0,x,y,v; i < n; i++){
        cin>>k;
        vector<int> b;
        for(int j=0;j<k;j++){
            cin>>x;
            b.pb(x);
        }
        for(int j=0;j<k;j++){
            cin>>v;
            if(j==k-1){
                a.pb({v,{b[i],b[0]}});
            }
            else{
                a.pb({v,{b[i],b[i+1]}});
            }
        }
    }
    sort(a.begin(), a.end());
    int ans = 0;

    for(piii i : a){
        if(onion(i.second.second, i.second.first)){
            ans+=i.first;
        }
    }
    cout<<ans;
}
