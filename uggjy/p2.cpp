#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m,n,k, t;
    cin>>m>>n>>k;
    for(int i = 0; i < k; i++){
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int ans = 0, last, l = 0, r = 0;
    for(int i = 0; i < n; i++){
            last = 0;
        for(int j = 0; j < m; j++){
            cout<<ans<<endl;
            if (l + r == k){
                cout<<ans;
                return 0;
            }
            if(j%2==0){
                last = a[k-1-r];
                cout<<a[k-1-r];
                r++;
            }
            else{
                ans+= 1 + last - a[l];
                l++;
            }
        }
    }
}



