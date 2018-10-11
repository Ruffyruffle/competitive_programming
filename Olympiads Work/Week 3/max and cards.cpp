#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
ll n,q,k;

void solve(vector<int> num, ll *fac, ll q){
    for(int i = n; i > 0; i--)
        {
            int in = q/fac[i-1];
            cout<<num[in]<<" ";
            num.erase(num.begin()+in);
            q%=fac[i-1];
        }
    cout<<"\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    ll fac[n+1];
    vector<int> num;
    fac[0] = 1;

    for(int i = 1 ; i < n+1; i++){
        fac[i] = fac[i-1] * i;
    }
    for(int a = 0; a < n; a++){
            num.push_back(a+1);
    }
    for(int j = 0; j < k; j++){
        cin>>q;
        solve(num,fac, q);
    }
}
