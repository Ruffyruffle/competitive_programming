#include<bits/stdc++.h>
using namespace std;
#define MAXN 300001
int n,k;
int a[MAXN], mx;
int psa[MAXN];

bool solve(int x){
    for(int i = k; i <=n; i++){
//        int l=0,r=i-k,mid,ans=-1;
//        while(r>=l){
//            mid=(l+r)>>1;
//            if(psa[i] - psa[mid] >= 0){
//                l=mid+1;
//                ans = mid;
//            }
//        }
    }
}

int main(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        psa[i] = psa[i-1] + a[i];
        mx = max(mx, a[i]);
    }
    int l=0,r=mx,mid;
    while(r>=l){
        mid = (l+r)>>1;
        if(check(mid)){
            l = mid+1;
        }
        else r = mid-1;
    }
    cout<<l;
}
