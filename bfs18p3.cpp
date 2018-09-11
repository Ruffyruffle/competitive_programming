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
typedef unsigned long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,x;
ll a[100000];

int main(){
    ll ans = 0;
    cin>>n>>x;
    MEM(a, 0);
    for (int i =0; i < n; i++){
        cin>>a[i];
    }
    n--;
//    while(x>0){
//        sort(a, a+(n+1));
//        if (a[n] == a[0] && a[n] == 0)
//            break;
////        xx = x;
//        //cout<<a[0];
//        //cout<<x;
//        double d = 1;
//        if (a[n] == a[n-1]){
//            bool ff = false;
//            //d = 1;
//            for(int i = n; i >=0; i--){
//                if(a[n] > a[i]){
//                    d = a[n] - a[i];
//                    ff = true;
//                    break;
//                }
//            }
//            if(!ff && a[n] == a[0]){
//                float y = floor(x/(n+1));
//                //cout<<y<<endl;
//                if (y > a[0]){
//                    y = a[0];
//                }
//                //cout<<( (n+1)*( (y/2) * (a[n] + a[n] - (y-1))))<<endl;
//                ans += ( (n+1) *( (y/2) * (a[n] + a[n] - (y-1))));
//                x-=y*(n+1);
//                for (int i = 0; i <n+1; i++){
//                    a[i] -= y;
//                }
//                if (x<1)
//                    break;
//            }
//        }
//        else
//            d = a[n] - a[n-1];
//        //cout<<d<<endl;
//        if (d>x)
//            d = x;
//        //cout<<((d/2) * (a[n] + a[n] - (d-1)))<<endl;
//        ans+=((d/2) * (a[n] + a[n] - (d-1)));
//        x -= d;
//        a[n] -=d;
//    }
    while(x--){
        if (a[n] == 0 && a[n] == a[0])
            break;
        sort(a, a+(n+1));
        ans+=a[n];
        a[n]--;
    }
    cout<<ans;
}
