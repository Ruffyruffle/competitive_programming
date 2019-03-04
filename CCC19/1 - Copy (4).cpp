#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define INF 0x3f3f3f3f
typedef pair<long long,long long> pii;
long long n,m,k,ans;
vector<long long> a;
long long mx[2*MAXN];
//long long dp[MAXN][101];
unordered_map<long long,long long> dp;
void build(){
    for(long long i = n-1; i > 0; --i) mx[i] = max(mx[i<<1], mx[i<<1|1]);

}
void modify(long long i, long long v){
    for(mx[i+=n]=v; i>1; i>>=1) mx[i>>1] = max(mx[i], mx[i^1]);
}

long long query(long long l, long long r){
    long long hi=-1;
    for(l+=n,r+=n; r>l; l>>=1, r>>=1){
        if(l&1){
            hi = max(hi, mx[l++]);
        }
        if(r&1){
            hi = max(hi, mx[--r]);
        }
    }
    return hi;
}

//int c=0;
long long solve(long long sum, long long cur, long long cs, long long free, long long mx){
    //c++;
    //if((mx-cs) * k > n-cur || cs > mx) return 0;
    //cout<<sum<<" "<<cur<<" "<<free<<endl;
    if(cur >= n) return sum;
    if(dp[cur*(mx+1) + free] > sum) return dp[cur*(mx+1) + free];
    long long ret = 0;
    for(long long i = max(0ll,k-free); i <=k; i++){
        long long tt = k-i;
        //cout<<cur<<" "<<i<<endl;
        ret = max(ret, solve(sum + query(cur, cur + i), cur+i, cs+1, free-tt ,mx));
    }
    return dp[cur*(mx+1) + free] = ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (long long i =0; i < n; i++){
        cin>>mx[n+i];
        a.pb(mx[n+i]);
    }
    build();

    long long d = (ceil(1.0*n/k));
    if(d == 2){
        for(long long i = n-k-1; i < k; i++){
            ans = max(ans, query(0,i+1) + query(i+1, n));
            //cout<<query(i+1,n)<<endl;
        }
    }
    else if(d==1){
        sort(a.begin(),a.end());
        ans = a[n-1];
    }
//    else {
//        for(long long i = 0; i < n; i++){
//            for(long long j = 1; j < k; j++){
//                dp[i+j][j+] = max(dp[i][j], dp[i])
//            }
//        }
//    }
    else ans = solve(0,0,0,(d*k-n),d);
    cout<<ans;
}
/*
6 3
2 5 7 1 4 7

*/
