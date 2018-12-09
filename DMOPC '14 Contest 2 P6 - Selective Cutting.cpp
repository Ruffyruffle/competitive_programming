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
#define MAXN 100001
using namespace std;
int n,q;
vector<int> c[20001];
int bit[MAXN];
int ans[MAXN];

void add(int i, int val){
    while(i<=MAXN){
        bit[i]+=val;
        i+= i&-i;
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans+=bit[i];
        i-= i&-i;
    }
    return ans;
}

struct query{
    int v,x,y,i;
};
vector<query> a;

bool cmp(query a, query b){return a.v>b.v;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);
    for (int i =0,x; i < n; i++){
        scan(x);
        c[x].pb(i+1);
    }
    scan(q);

    for(int i = 0,x,y,v; i < q; i++){
        scan(x); scan(y); scan(v);
        a.pb({v,x+1,y+1,i});
    }
    sort(a.begin(), a.end(), cmp);

    //i can't fucking read

//    for(int i = 0; i < q; i++){
//        while(a[i].v > cur){
//            cur++;
//            for(int j : c[cur]){
//                //cout<<j;
//                add(j, cur);
//            }
//        }
//        //cout<<a[i].y<<" "<<a[i].x<<endl;
//        ans[a[i].i] = sum(a[i].y) - sum(a[i].x-1);
//    }
    int cur = 20001;

    for(int i = 0; i < q; i++){
        while(a[i].v < cur){
            cur--;
            for(int j : c[cur]){
                add(j, cur);
            }
        }
        //cout<<sum(5)<<endl;
        ans[a[i].i] = sum(a[i].y) - sum(a[i].x-1);
    }
    for(int i = 0; i < q; i++){
        cout<<ans[i]<<endl;
    }
}
