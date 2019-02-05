#include<bits/stdc++.h>
using namespace std;
long long x,y;

inline long double d(int xx, int yy){
    return sqrt(pow(xx-x,2) + pow(yy-y,2));
}


int main(){
    long long x2,y2,x3,y3; cout<<fixed<<setprecision(3);
    long double ans=10000000000.0;
    cin>>x>>y>>x2>>y2>>x3>>y3;
    for(int i = x2; i<=  x3; i++){
        for(int j = y2; j <= y3; j++){
            ans = min(ans, d(i,j));
        }
    }
    cout<<ans<<'\n';

}
