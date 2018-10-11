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
    n = 1;
    for(int i = 0; i < n; i++){
            last = 0;
        for(int j = 0; j < m; j++){
            if (l + r == k){
                break;
            }
            if(j%2==0){
                if (last >= a[k-1-r]){
                    ans += (last-a[k-1-r])+1;
                    last = (last-a[k-1-r])+1;
                }
                else last = a[k-1-r];
                r++;
            }
            else{
                ans+= 1 + last - a[l];
                last = a[l]+1;
                l++;
            }
        }
    }
    cout<<ans;
}
