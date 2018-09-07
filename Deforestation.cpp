#include<iostream>
#include <numeric>
#include<stdio.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n,d;
    cin>>n;
    int ma[1000000];
    ma[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin>>d;
        ma[i] = d + ma[i-1];
    }
    cin>>n;
    int a,b,c;
    for(int i = 0; i < n; i++){
            cin>>a>>b;
            //cout<<a<<b;
            c = ma[b+1] - ma[a];
           cout<<c<<"\n";
    }
    //cout<<endl;
}
