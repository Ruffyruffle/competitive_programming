#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define endl '\n'
typedef unsigned long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

ll powTen(ll n){
//    ll n1=10, y = 1;
//    while(n>1){
//        if (n%2 == 0){
//           n1 = n1*n1;
//           n /= 2 ;
//        }
//        else{
//            y = n1*y;
//            n1 = n1*n1;
//            n = (n-1)/2;
//        }
//    }
//    return n*n1;
    return (n == 2) ? (100) : (pow(10,n));
}

int exp(ll n, ll k){

    ll n1=n, y = 1;
    ll a = powTen(k);
//    if (k%2==1)
//        a = powTen(k)*10;
//    else
//        a = powTen(k);
    //cout<< "."<<a<<"."<<k<<".";
    //cout<<a;
//    while(n>0){
//        if (n%2 == 0){
//           n1 *= n1;
//           n1 %= a;
//           n /= 2;
//        }
//        else{
//            y = (y*n)%a;
//            //y %=a;
//        }
//    }
    while(n1>0){
        if (n1 % 2 == 1){
            y= (y*n)%a;
        }
        n=(n*n)%a;
        n1/=2;
    }
    //n = n1%a;
    cout<<y%a<<endl;
    //cout<<n/(a/10)<< " " << n%a<<endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n,k;
    cin>>t;

    for(int i = 0; i < t; i++){
        cin>>n>>k;
        ld b = n*log10(n);
        ld ba, bb;
        ba = floor(b);
        bb = b - ba;
        bb = pow(10,bb);

        string s = to_string(bb);
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        //cout<<bb;
        //cout<<bb<<l;
        //cout<<powTen(s.length()-k)<<endl;
        cout<<s.substr(0,k) << " ";
        exp(n,k);
    }
}
