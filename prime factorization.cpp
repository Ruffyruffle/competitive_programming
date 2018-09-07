#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

void pfactorize(int m){
    while (m%2==0){
        cout<<"2 ";
        m=m>>1;
    }
    for (int i = 3; i <= sqrt(m); i+=2)
        while(m%i ==0){
            cout<<i<<" ";
            m/=i;
        }
    if (m>1)
        cout<<m;
    cout<<"\n";
}

int main(){
    int n,m;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>m;
        pfactorize(m);
    }
}
