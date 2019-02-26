#include<bits/stdc++.h>
using namespace std;
#define MAXN 2001
#define pb push_back
long long n,k;
vector<long long> a;
long long b[MAXN][MAXN];
int main(){
    cin>>k>>n;
    for(long long i = 0,x; i < n; i++){
        cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    long long cur = 1, curt=2;
    b[1][1] = 0;
    for(long long i = 2; i <= ceil(sqrt(n)); i++){
        for(long long j = 1; j <= i; j++){
            if(j == 1 || j == i){
                b[i][j] = ceil((b[i-1][1] + k) / 2.0);
            }
            else b[i][j] = ceil((b[i-1][j] + b[i-1][j-1] + k*2) / 2.0);
            //cout<<b[i][j]<<" ";
        }
        sort(b[i]+1, b[i]+i+1);
        //cout<<endl;
    }
    while(n>cur){
        long long i = 1;
        while(i <= curt && n>cur){
            if(a[cur] >= b[curt][i]) i++;
            //cout<<a[cur]<<endl;
            cur++;
        }
        if(!(i==curt+1)) break;
        curt++;
    }
    cout<<curt-1;
    /*
    0
    2.5 2.5
    3.75 7.5 3.75
    */
}
