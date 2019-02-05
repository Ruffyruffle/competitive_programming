#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; double ans;
    cin>>n;
    for(int i = 0,x; i < n; i++){
        cin>>x; ans+=x;
    }
    cout<<fixed<<setprecision(1)<<ans/n<<endl;

}
