#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
int n;ll ans;
vector<pair<int,int>> a;
vector<int> x,y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    scan(n);
    for(int i = 0, t, tt; i < n; i++){
        scan(t);scan(tt);
        a.pb({t,tt});
        x.pb(t);
        y.pb(tt);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int xx, yy;
        xx = x[n/2], yy = y[n/2];

    for(int i = 0; i < n; i++){
         ans += (abs(xx - a[i].first) + abs(yy -a[i].second));
    }

    cout << ans << endl;
}
