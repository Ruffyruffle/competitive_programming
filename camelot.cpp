#include<bits/stdc++.h>
using namespace std;

#define pb push_back
int n;
vector<pair<int,int>> a;
vector<int> x,y;

int calc(int x, int y){
    int an = 0;
    for(int i = 0; i < n; i++){
         an += max(abs(x - a[i].first), abs(y-a[i].second));
    }
    return an;
}

int main(){
    cin>>n;
    for(int i = 0, t, tt; i < n; i++){
        cin>>t>>tt;
        a.pb({t,tt});
        x.pb(t+tt);
        y.pb(t-tt);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int xx, yy;
    if(n%2 ==1)
        xx = x[n/2] - y[n/2], yy = x[n/2] + y[n/2];
    else
        xx = (x[n/2] + x[n/2 - 1]) / 2, yy = (y[n/2] + y[n/2 - 1]) / 2;

    int xt = xx, yt = yy;
    xx = xt + yt; yy = xt - yt;

    int ans = 0x3f3f3f3f;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            ans = min(calc(xx+i, yy+j), ans);
        }
    }
    cout << ans << endl;
}
