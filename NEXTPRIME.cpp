#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int sieve(int n){
    bool si[n+1];
    memset(si, true, sizeof(si));
    for (int i = 2; i*i<n+1; i++) if (si[i] == true)
            for (int j=i*2; j<=n; j += i) si[j] = false;

    int a = 0;
    for (int i = 0; i < n+1; i++) if (si[i] == true)
        a++;
    return a;
}
int main()
{
   int b = sieve(100000000);
   cout << b;
}
