#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int mimi(int a[], int n, int siz){
    bool si[n+1];
    memset(si, true, sizeof(si));
    for (int i = 2; i*i<n+1; i++) if (si[i] == true)
            for (int j=i*2; j<=n; j += i) si[j] = false;

    bool b[siz];
    memset(b, true, sizeof(b));

    for (int p=n; p>=2; p--)
        if (si[p])
            for (int i = 0; i < siz; i++){
              if (a[i] % p != 0){
                b[i] = false;
                break;
              }
              if(b[i]){
                return p;
              }
            }
    return 0;
}
int main()
{
    int n, big, c;
    cin>>n;
    int a[n];
    for (int i = 0; i<n;i++){
        cin>>a[i];
        if (a[i] > big)
            big = a[i];
    }
    c = mimi(a, big, n);
    if (big == 0)
        cout<<"DNE";
    else
        cout<<c;
}
