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
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a[n+1];
    int fwc= INF;
    int fnwc = INF;

//    int a[n+1];
//    a[0] = 0;
    int b;
    a[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin>>b;
        a[i] = b;
        if (fwc==INF && b ==0)
            fwc = i;
    }
    for(int i = fwc; i < n+1; i++){
        if (a[i] != 0){
            fnwc = a[i];
            break;
        }
    }
    for(int i = fwc; i < n+1; i++){
        if (a[i] == 0){
            a[i] = fnwc;
        }
    }
    if(is_sorted(a,a+(n+1)))
        cout<<"YES";
    else
        cout<<"NO";

//    auto *ptr[n];
//    int w = 0;
//    for (int i =0; i < n; i++){
//        cin>>b;
//        a[i] = b;
//        if(b == 0){
//            ptr[i] = &w;
//        }
//        else{
//            ptr[i] = &a[i];
//        }
//    }
//    for(int i = 0; i < n;i++){
//        for(int j = 0; j < n; j++){
//            if (*ptr[j] > *ptr[j+1]){
//                w++;
//                goto no;
//            }
//        }
//        cout<<"YES";
//        return 0;
//        no:;
//    }
//    cout<<"NO";
//}
}
