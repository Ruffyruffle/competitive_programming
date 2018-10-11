#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ll n,w,a,mn,mx,last, mx2, b;
vector<ll> c;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w;
    for (int i =0; i < n; i++){
        cin>>a; c.pb(a);
    }
    last = w;
    sort(c.begin(), c.end());
//    if (w>c[n-1]){
//        for(int i = 1; i < n+1; i++){
//            mn+=min(abs(c[n-i] - w), abs(c[n-i] - last));
//            last = c[n-i];
//            b++;
//        }
//    }
//    else{
//        for(int i = 0; i < n; i++){
//            mn+=min(abs(c[b] - w), abs(c[b] - last));
//            last = c[b];
//            b++;
//        }
//    }
    if(w>c[0] && w < c[n-1])
        mn = abs(c[0] - w) + abs(c[n-1] - w);
    else
        mn = c[n-1]- c[0] + min(abs(w - c[0]), abs(w-c[n-1]));

    last = w;
    ll l = 0,en = n-1;
    //flag2 = (abs(last-c[l]) > abs(last - c[en])) ?false:true;
    for(int i = 0; i < n; i++){
        if ((i+1)%2){
            //cout<<c[en]<<" ";
            mx+=max(abs(c[en] - w), abs(c[en] - last));
            last = c[en];
            en--;
        }
        else{
            //cout<<c[l]<<" ";
            mx+=max(abs(c[l] - w), abs(c[l] - last));
            last = c[l];
            l++;
        }
        //cout<<mx<<endl;
    }
    last = w;
    l = 0,en = n-1;
    for(int i = 0; i < n; i++){
        if (i%2){
            //cout<<c[en]<<" ";
            mx2+=max(abs(c[en] - w), abs(c[en] - last));
            last = c[en];
            en--;
        }
        else{
            //cout<<c[l]<<" ";
            mx2+=max(abs(c[l] - w), abs(c[l] - last));
            last = c[l];
            l++;
        }
        //cout<<mx<<endl;
    }
    cout<<mn<<" "<<max(mx,mx2);
}
