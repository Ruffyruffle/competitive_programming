#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
bool isPal(string n){
    if (n == string(n.rbegin(), n.rend()))
        return true;
    return false;
}
int main(){
 long long int q,k,m,n;
 int b = 0;
 cin>>q>>k;
 for (long long int i = 0 ; i<q;i++){
    int ans = 0;
    cin>>m>>n;
    if (m%k == 0)
         b = m;
    else
         b = (m+k-(m%k));

    for(long long int j = b; j<(n+1); j+=k){
        if (isPal(to_string(j)) == true)
                ans++;
    }
    cout<<ans<<"\n";
 }
}
