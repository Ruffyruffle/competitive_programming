#include <bits/stdc++.h>

#define MAXN 1001
using namespace std;
int a[MAXN][MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sz = 0;
        for(int j = 0 ; j < n; j++){
            if(a[i][j] != i*n+j+1)
                sz++;
            //cout<<i*n+j<<endl;
        }
        ans = max(sz,ans);
    }
    cout<<ans<<endl;

}
