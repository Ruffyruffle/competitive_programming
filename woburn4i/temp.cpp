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
#define MAXN 200001
using namespace std;
int n,m,ans,k;
int sz;
int a[MAXN];
int decomp[450][MAXN];
//bool b[MAXN][];

void update(int k, int x){
    int block = k/sz;
    //cout<<block<<endl;
    for(int i = 1; i <= sqrt(a[k]); i++) {
        if(a[k]%i==0){
            decomp[block][i]--;
            if(i!=a[k]/i)decomp[block][a[k]/i]--;
        }
    }

    a[k] = x;
    for(int i = 1; i <= sqrt(a[k]); i++){
        if(a[k] % i == 0){
            decomp[block][i]++;
            if(i!=a[k]/i)decomp[block][a[k]/i]++;
            //cout<<a[k]<<" "<<i<<" "<<a[k]/i<<endl;
        }
        //cout<<a[k]<<" "<<i<<endl;
    }
    //cout<<x<<endl;
}
int query(int l, int r, int x){
    //int lb = l/sz+1, rb = r/sz-1;
    int ret = 0;
    while(l <= r && l%sz!=0){
        if(a[l++]%x==0)ret++;
    }
    while(l + sz-1 <= r){
        ret+=decomp[l/sz][x];
        l+=sz;
    }
    while(r>=l){
        if(a[l++]%x==0)ret++;
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q,x;
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sz = ceil(sqrt(n));
    for(int j = 0; j < n; j++){
        //update(i,a[i]);
        int block = j/sz;
        for(int i = 1; i <= sqrt(a[j]); i++){
            if(a[j] % i == 0){
                decomp[block][i]++;
                if(i!=a[j]/i)decomp[block][a[j]/i]++;
            }
        }
    }
    int o,l,r;
    while(q--){
        cin>>o>>l>>r;
        if(o==1){
            cin>>x;
            cout<<query(l-1,r-1,x)<<endl;
        }
        else{
            update(l-1,r);
        }
    }
}
