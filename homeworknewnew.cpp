#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define MAXN 10000001
using namespace std;

int main(){
    int si[MAXN];
    memset(si, 0, sizeof(si));

    for (int i = 2; i<MAXN+1; i++) if (si[i] == 0)
        for (int j=i; j<=MAXN; j += i) si[j]++;

    int n;
    cin>>n;
    int a, b, k;
    for (int i = 0; i < n; i++){
        cin>>a>>b>>k;
        int pc = 0;
        for (int j = a; j <= b; j++){
            if (si[j] == k)
                pc++;
        }
        cout<<"Case #" << i+1<< ": " <<pc<<endl;
    }
}
//5 15 2
