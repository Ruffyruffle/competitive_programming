#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
int n;
vector<pair<int,int>> a;
vector<int> x,y;

ll calc(int x, int y){
    ll an = 0;
    for(int i = 0; i < n; i++){
         an += max(abs(x - a[i].first), abs(y-a[i].second));
    }
    return an;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
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
        xx = x[n/2], yy = y[n/2];
//    else
//        xx = (x[n/2] + x[n/2 - 1]) / 2, yy = (y[n/2] + y[n/2 - 1]) / 2;

    int xt = yy, yt = (xx - yy) / 2;
    xx = xt + yt; yy = yt;
    //cout<<xx<<" " << yy<<endl;

    ll ans = 0x3f3f3f3f3f3f3f3f;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            ans = min(calc(xx+i, yy+j), ans);
        }
    }

//    ll ans2 =  0x3f3f3f3f;
//    for(int i = 0 ; i < 10000; i++){
//        for(int j = 0 ; j < 10000; j++){
//            ans2 = min(ans2, calc(i,j));
//        }
//    }
    cout << ans << endl;//<<ans2;
}
