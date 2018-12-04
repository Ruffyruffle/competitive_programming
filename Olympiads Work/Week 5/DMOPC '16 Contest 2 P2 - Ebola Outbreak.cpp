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
#define MAXN 1000000
using namespace std;
int n,m,k;
vector<int> par, rk;
vector<int> ebola;
void create(int v){
    par[v] = v;
    rk[v] = 0;
}

int look(int a){
    if(a==par[a]) return a;
    return par[a] = look(par[a]);
}

void onion(int a, int b){
    a=look(a); b=look(b);
    if(a!=b){
        if(rk[a] < rk[b])
            swap(a,b);
        par[b] = a;
        if(rk[a] == rk[b]) rk[a]++;
    }
}



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    par.resize(n+1); rk.resize(n+1);
    for(int i = 1; i <=n; i++){
        create(i);
    }
    cin>>m;
    for (int i =0,x,y; i < m; i++){
        cin>>k;
        cin>>y;
        for(int j = 1; j< k; j++){
            cin>>x;
            onion(x,y);
            y = x;
        }
    }
    int a = look(1);
    for(int i = 1; i <= n; i++){
        if(a == look(i)){
            ebola.pb(i);
        }
    }
    cout<<ebola.size()<<endl;
    for(int i : ebola){
        cout<<i<<" ";
    }
}
