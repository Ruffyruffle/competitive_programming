#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 100000
using namespace std;
int n,k;
vector<int> par, rk;

void create(int v){
    par[v] = v;
    rk[v] = 0;
}

int fnd(int v){
    if(v==par[v]) return v;
    return par[v] = fnd(par[v]);
}

void onion(int a, int b){
    a = fnd(a);
    b=fnd(b);
    if(a!=b){
        if(rk[a] < rk[b])
            swap(a,b);
        par[b] = a;
        if(rk[a]==rk[b]) rk[a]++;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    par.resize(n+1);
    rk.resize(n+1);
    char q;
    for(int i = 0; i <= n; i++){
        create(i);
    }
    for(int i = 0,x,y; i < k; i++){
        cin>>q>>x>>y;
        if(q=='A'){
            onion(x,y);
        }
        else if(q=='Q')
            cout<<(fnd(x) == fnd(y) ? 'Y' : 'N')<<endl;
    }
}
