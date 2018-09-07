#include <cstdio>
#include <algorithm>
#include <iostream>

#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)

using namespace std;

int n;
double bp[10001], pri[10001];

int main(){

    scanf("%d", &n);
    For(i,0,n){
        cin>>pri[i+1];
    }

    For(i,0,n){
        bp[i] = 0x3f3f3f3f;
    }

    bp[0] = 0;
//bp[n] == best price after first n items
    For(i,1,n+2){
        bp[i] = bp[i - 1] + pri[i];

        if(i-2 >= 0){
            bp[i] = min(bp[i], bp[i-2] + (pri[i] + pri[i-1]) - (min(pri[i], pri[i-1])/2));
        }
        if (i-3>=0){
            bp[i] = min(bp[i], bp[i-3] + pri[i] + pri[i-1] + pri[i-2] - (min(pri[i-2], min(pri[i], pri[i-1]))));
        }
//        cout<<i;
//        cout<<pri[i]<<"\n";
    }

// for (int i = 1; i <= n + 1; i++) {
//        if (bp[i] == 0x3f3f3f3f) bp[i] = bp[i - 1] + pri[i];
//        else bp[i] = min(bp[i], bp[i - 1] + pri[i]);
//        if (i + 1 <= n) {
//            int m = min(pri[i], pri[i+1]);
//            bp[i + 1] = min(bp[i+1], bp[i - 1] + pri[i] + pri[i+1] - m / 2.0f);
//        }
//        if (i + 2 <= n) {
//            int m = min(pri[i], min(pri[i+1], pri[i+2]));
//            bp[i + 2] = min(bp[i + 2], bp[i - 1] + pri[i] + pri[i+1] + pri[i + 2] - m);
//        }
////        cout<<bp[i-2] << "\n";
//    }

//    float a;
//    For(i,0,n){
//    if (bp[i]!= 0x3f3f3f3f)
//        a+= bp[i];
//    }

    printf("%.1f\n", bp[n]);


    return 0;







}
