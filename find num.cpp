#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("find_the_number_data14_100000.txt", "r", stdin);
    int n, a = 0, c = 0;
    cin>>n;
    int b = (n-1)*n/2;
    for (int i = 0; i < n-1; i++){
        cin>>c;
        a+=c;
    }
    cout<<(b-a);
}
