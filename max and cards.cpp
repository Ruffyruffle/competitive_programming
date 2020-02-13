#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int main(){
    int n,q,k;
    cin>>n>>k;
    int fac[n+1];
    vector<int> num;
    fac[0] = 1;

    for(int i = 1 ; i < n+1; i++){
        fac[i] = fac[i-1] * i;
    }

    for(int j = 0; j < k; j++){
        cin>>q;
        num.clear();
        for(int a = 0; a < n; a++){
            num.push_back(a+1);
        }
        for(int i = n; i > 0; i--)
        {
            int in = q/fac[i-1];
            cout<<num[in]<<" ";
            num.erase(num.begin()+in);
            q%=fac[i-1];
        }
        cout<<"\n";
    }
}
