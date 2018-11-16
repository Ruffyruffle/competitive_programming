#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll n;
pair<pair<ll, ll>, ll> p[100001];
ll DP[100001];

bool cmp2(ll a, pair<pair<ll, ll>, ll> b){
    return (a <= b.first.first);
}

bool cmp(pair<pair<ll, ll>, ll>  a, pair<pair<ll, ll>, ll>  b){
    return (b.first.first > a.first.first);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i].first.second>>p[i].first.first>>p[i].second;
        p[i].first.first += p[i].first.second - 1;
    }
    sort(p, p+1+n, cmp);
    DP[0] = 0;
    for(int i = 1; i <= n; i++){
        ll last = upper_bound(p+1, p+i+1, p[i].first.second, cmp2) - p - 1;
        DP[i] = max(DP[i-1], DP[last] + p[i].second);
    }
    cout<<DP[n];
}
