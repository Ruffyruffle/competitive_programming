#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
vector<pair<int,int>> a;
int n;
int solve(int x, int y){
   unordered_map<double, int> d;
   int ret = 0;
   for(int i = 0; i < n; i++){
        double t = sqrt(pow(a[i].s - y,2) + pow(a[i].f - x, 2));
        if(!d[t]){
            d[t] = 1;
            ret++;
        }
   }
    return ret;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int ans = 0x3f3f3f3f;
    cin>>n;
    for(int i = 0,x,y,z; i < n; i++){
        cin>>x>>y;
        a.push_back({x,y});
    }
    for(int i = -300; i <= 300; i++){
        for(int j = -300; j <= 300; j++){
            ans = min(ans, solve(i,j));
        }
    }
    cout<<ans<<endl;

}
