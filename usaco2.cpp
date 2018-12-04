/*
ID: stevenu1
TASK: ride
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

string a,b;
int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    cin>>a>>b;

    int ans = ((int)a[0]) - 64, ans2 = ((int)b[0]) - 64;
    for(int i = 1; i < a.length(); i++){
        ans*= ((int)a[i]) - 64;
    }
    for(int i = 1; i < b.length(); i++){
        ans2*= ((int)b[i]) - 64;
    }
    cout<<(ans%47 == ans2%47 ? "GO" : "STAY")<<'\n';
    return 0;
}
