#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
//bool * sieve(int n){
//    static bool si[1000000000];
//    memset(si, true, sizeof(si));
//    for (int i = 2; i*i<n+1; i++) if (si[i] == true)
//            for (int j=i*2; j<=n; j += i) si[j] = false;
//    return si;
//}
//bool * sieve(int n){
//    static bool si[1000000000];
//    memset(si, false, sizeof(si));
//    si[2] = si[3] = true;
//
//    for (int x = 1; x * x < n; x++)
//        for (int y = 1; y*y < n; y++){
//            int t = (4*x*x) + (y*y);
//            if (t <= n && (t% 12 == 1 || t % 12 == 5))
//                si[t] ^= true;
//            t = (3*x*x) + (y*y);
//            if (t <= n && t %12 == 7)
//                si[t] ^= true;
//            t = (3*x*x) - (y*y);
//            if ((x>y) && (t <= n) && (t%12 == 11))
//                si[t] ^= true;
//        }
//
//    for (int i = 5; i*i < n; i++)
//        if (si[i])
//            for (int j = i*i; j<n; j+= i*i) si[j] = false;
//
//    return si;
//}
bool * sieve(int n){
    static bool si[10000001];
    memset(si, false, sizeof(si));
    si[2] = si[3] = true;

    for (int x = 1; x * x < n; x++)
        for (int y = 1; y*y < n; y++){
            int t = (4*x*x) + (y*y);
            if (t <= n && (t% 12 == 1 || t % 12 == 5))
                si[t] ^= true;
            t = (3*x*x) + (y*y);
            if (t <= n && t %12 == 7)
                si[t] ^= true;
            t = (3*x*x) - (y*y);
            if ((x>y) && (t <= n) && (t%12 == 11))
                si[t] ^= true;
        }

    for (int i = 5; i*i < n; i++)
        if (si[i])
            for (int j = i*i; j<n; j+= i*i) si[j] = false;

    return si;
}
int primacity(int a, int n, int k, bool *si){
    int pc = 0, ans = 0;
    for (int i = a; i <= n; i++){
        pc = 0;
        for (int p=2; p < n; p++)
           if (si[p])
              if (i % p == 0)
                pc++;
        if (pc == k){
            ans++;
        }
    }
    return ans;
}
int main(){
    int n, big = 0;
    cin>>n;
    int a[n], b[n], k[n];
    for (int i = 0; i < n; i++){
        cin>>a[i]>>b[i]>>k[i];
        if (b[i] > big)
            big = b[i];
    }
    bool *primes = sieve(big);
    for (int i = 0; i < n; i++)
        cout<<"Case #" << i+1<< ": " <<primacity(a[i],b[i],k[i], primes)<<endl;
}

//5 15 2
