#include <stdio.h>
#include <iostream>

int main(){

    long long int n = 0, longest = 0, heights = 0;
    long long int a [2001];
    long long int b [4002];

    std::cin>>n;

    for (int i = 0; i < 2001; i++){
        if (a[i] != 0){
            a[i] = 0;
        }
    }
    for (int i = 0; i < 4002; i++){
        if (b[i] != 0){
            b[i] = 0;
        }
    }

    for (long long int i = 0; i < n; i++){
        int c;
        std::cin>>c;
        if(c != 0){
            a[c]++;
        }
    }


//    for (int i = 0; i < 2001; i++){
//        if (a[i] > 0){
//            for (int j = 0; j < 2001; j++){
//                    if (i == j){
//                       // b[i+j] += a[i] >> 1;
//                    }
//                    else if (a[i] < a[j]){
//                        b[i+j] += a[i];
//                    }
//                    else if (a[i] > a[j]){
//                        b[i+j] += a[j];
//                    }
//                    else if (a[i] == a[j]){
//                        b[i+j] += a[i];
//                    }
//
//            }
//        }
//    }
    for(int i = 1; i < 2001; i++) {
        if (a[i]) {
            for(int j = i; j < 2001; j++) {
                if (i == j) {
                    b[i + j] += a[i] >> 1;
                }
                else if (a[j] != 0) {
                        b[i+j] += std::min(a[i], a[j]);
              //      if (a[i] < a[j]){
              //        b[i+j] += a[i];
             //       }
             //       if (a[i] > a[j]){
             //           b[i+j] += a[j];
              //      }

                }
            }
        }
    }

//        for (int i = 4002; i > 0; i--){
//        if (b[i] > 0){
//            std::cout << b[i];
//            longest = i;
//            break;
//        }
//    }
//    for (int i = 0; i < 4002; i++){
//            if (b[i] > 0){
//                heights++;
//            }
//    }

    for(int i = 1; i < 4002; i++) {
        if(b[i] > longest) {
            longest = b[i];
            heights = 1;
        } else if(b[i] == longest) {
            heights += 1;
        }
    }
    std::cout<<longest<<" "<<heights;

    return 0;
}
