#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define MAXN 10000001
using namespace std;

int main(){
    bool si[MAXN];
    memset(si, false, sizeof(si));
    si[2] = si[3] = true;

    for (int x = 1; x * x < MAXN; x++)
        for (int y = 1; y*y < MAXN; y++){
            int t = (4*x*x) + (y*y);
            if (t <= MAXN && (t% 12 == 1 || t % 12 == 5))
                si[t] ^= true;
            t = (3*x*x) + (y*y);
            if (t <= MAXN && t %12 == 7)
                si[t] ^= true;
            t = (3*x*x) - (y*y);
            if ((x>y) && (t <= MAXN) && (t%12 == 11))
                si[t] ^= true;
        }

    for (int i = 5; i*i < MAXN; i++)
        if (si[i])
            for (int j = i*i; j<MAXN; j+= i*i) si[j] = false;

    int n, big = 0;
    cin>>n;
    int a, b, k;
    for (int i = 0; i < n; i++){

        cin>>a>>b>>k;
        int pc = 0, ans = 0;
        for (int i = a; i <= b; i++){
            pc = 0;
            for (int p=2; p < b; p++)
               if (si[p])
                  if (i % p == 0)
                    pc++;
            if (pc == k){
                ans++;
            }
        }
        cout<<"Case #" << i+1<< ": " <<ans<<endl;
    }
}

//5 15 2
