#include <bits/stdc++.h>
using namespace std;
int n, b[17], dp[1<<15];

int check(int mask){
    vector<int> a;
    for(int i=0; i<n; i++){
        if(mask & (1<<i))
            a.push_back(b[i]);
    }
    if (a.size() == 1)
        return true;
    bool in = true, de = true;

    for(int i = 1; i < a.size()+1; i++){
        if(a[i] > a[i-1])
            de = false;
        if (a[i] < a[i-1])
            in = false;
    }
    return de || in;
}

int solve(int mask){
    if(dp[mask] != -1)
        return dp[mask];
    if(check(mask)){
        dp[mask] = 1;
        return dp[mask];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(mask & (1<<i))
        ans |= solve(mask ^ (1<<i));

    }
    return dp[mask] = !ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i<6; i++){
        for(int j=1; j<4; j++){
            cin>>n;
            memset(dp, -1, sizeof(dp));
            for(int k=0; k<n; k++) {
                cin>>b[k];
            }
            cout<<(solve((1<<n)-1) ? "B" : "A");
        }
        cout<<"\n";
    }

}
