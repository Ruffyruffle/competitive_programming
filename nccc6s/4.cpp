#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1000000
typedef long long ll;
using namespace std;
ll a,b,c,d,q;
ll pre[10000001];
ll f(int x){
    if(0>=x) return 1;
    if(x<10000001) return pre[x];
    return f(x/a-b) + f(x/c-d);
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(a);scan(b);scan(c);scan(d);scan(q);
    int x; pre[0] = 1;
    for(int i = 1; i < 10000001; i++){
        pre[i] = pre[max(0ll,i/a-b)] + pre[max(0ll,i/c-d)];
    }
    while(q--){
        scan(x);
        cout<<f(x)<<'\n';
    }

}
