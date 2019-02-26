#include<bits/stdc++.h>
int n;
#define MAXN 1
using namespace std;

int main(){
    int x,y,z;
    cin>>n;
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin>>x>>y>>z;
        if(255>=x&&x>=240 && y>=0 && 200>=y && z>=95 && 220 >=z)
            ans++;
    }
    cout<<ans;

}
