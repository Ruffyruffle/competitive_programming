#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int sumPrime(int n){
    bool si[n+1];
    memset(si, true, sizeof(si));
    for (int i = 2; i*i<n+1; i++) if (si[i] == true)
            for (int j=i*2; j<=n; j += i) si[j] = false;
    int sum = 0;
    for (int p=2; p<=n; p++)
       if (si[p])
          sum += p;
    return sum;
}
int main()
{
    int a[5];
    cin >>a[0] >> a[1] >> a[2]>>a[3] >> a[4];
    for (int i = 0; i < 5; i++) cout<<sumPrime(a[i]) << "\n";
}
