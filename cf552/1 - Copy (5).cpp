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
int n,m,ans;
int a[MAXN]; bool b[MAXN];
int decomp[450];
int de2[450];
//bool b[MAXN][];
bool clean[MAXN];

void update(int k){
    int block = k/sz;
    a[k] = 0;
    decomp[block] = 0;
    for(int i = sz*block; i <= min(n-1, block*sz + sz - 1); i++){
        decomp[block]+=(b[i]?a[i]:0);
        de2+=b[i];
    }
}
void cl(int i){
    int block = i/sz;
    decomp[block]=0;
    de2[block] = 0;
}
int query(int i, int x){
    int l=i, r=i;
    int lc=0,rc=0;
    int ret = 0;
    while(m > lc + b[l] && l&sz!=0){
        l--; lc += b[l];
        if(b[l])ret+=a[l];
        clean[l/sz] = 1;
    }
    while(l > sz && m >= lc + de2[l/sz]){
        ret+=decomp[l/sz];
        l-=sz;

    }
    while(l>=0&& m > lc){
        if(b[l]){ret+=a[l--];lc++;}
    }




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
    cin>>n>>m;
    for (int i =0; i < n; i++){
        cin>>a[i];
        b[a[i]] = i;
    }



}
