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
#define MAXN 1000000
using namespace std;
int n,v=0;
int bit[MAXN];
unordered_map<int,int> id, rk;

void add(int i, int val){
    while(i <= MAXN){
        bit[i]+=val;
        i+=(i&-i);
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i-=(i&-i);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n);


    struct que{
        char o; int x, r;
    };
    vector<que> a(n);
    vector<int> rks;
    char o;

    for (int i =0,x,r; i < n; i++){
        o = getchar();
        if (o=='N'){
            scan(x); scan(r);
            a[i] = {o,x,r};
            rks.pb(r);
        }
        else if (o=='M'){
            scan(x); scan(r);
            a[i] = {o,x,r};
            rks.pb(r);
        }
        else{
            scan(x);
            a[i] = {o,x,0};
        }
    }
    sort(rks.begin(), rks.end());
    unordered_map<int,int> toi;

    for(int i = 1; i <= rks.size(); i++){
        toi[rks[i-1]] = i;
    }

    for (int i =0,x,r; i < a.size(); i++){
        x = a[i].x; r = toi[a[i].r];
        if (a[i].o=='N'){
            add(r,1);
            id[x] = r;
            rk[r] = x;
            v++;
        }
        else if (a[i].o=='M'){
            add(id[x], -1);
            id[x] = r;
            rk[r] = x;
            add(r, 1);
        }
        else{
            int l = 1; r = MAXN;
            while (l <= r){
                int mid = (l+r)>>1;
                if(v-x < sum(mid))
                    r = mid-1;
                else
                    l = mid+1;
            }
            cout<<rk[l]<<endl;
        }
    }
}
