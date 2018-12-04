#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<double, double> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
vector<pii> a;
double b=0,c=0;
vector<int> xx,yy;

int calc(int x, int y){
    int ans = 0,s;
    for(int i = 0; i < n; i++){
        s = max(abs(a[i].first-x),abs(a[i].second - y));
        ans += s;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y; i < n; i++){
        cin>>x>>y;
        xx.pb(x); yy.pb(y); a.pb({x,y});
        b+=x;c+=y;
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    int mx, my;
    if(n%2 == 0){
        mx = (xx[n/2] + xx[n/2 +1] )/2;
        my = (yy[n/2] + yy[n/2 +1] )/2;
    }
    else {
        mx = xx[n/2];
        my = yy[n/2];
    }
    b/=n;c/=n;
    int mn = -1, mi = INF, ans = INF;
    for(int i = 0; i < n; i++){
        if(abs(mx-xx[i]) + abs(my-yy[i]) < mi){
            mi = abs(mx-a[i].first) + abs(my-a[i].second);
            mn = i;
        }
    }

    ans = min(ans, calc(mx,my)); ans = min(ans, calc(b,c));

    for(int i = 0; i < n; i++){
        ans = min(calc(a[i].first, a[i].second), ans);
    }

    for(int i = -5; i <=5; i++){
        for(int j = -5; j <=5; j++){
            ans = min(ans, calc(mx+i, my + j));
        }
    }

    int ans2 = INF, y;
    int t,t2;
    for(int k = 0; k < 10000; k++){
        for(int j = 0; j < 10000; j++){
            for(int i = 0,x; i < n; i++){
                x= max(abs(a[i].first-k),abs(a[i].second - j));
                y += x;
            }
            if(ans2 > y){
                ans2 = min(ans2,y);
                t = k; t2 = j;
            }
            y = 0;
        }
    }
    cout<<ans<<" " << ans2;


/*
10
3289 5983
2595 250
4 1
5 2
7 3
4910 9987
2818 4928
4295 2094
2490 5209
6359 2094
*/



}
