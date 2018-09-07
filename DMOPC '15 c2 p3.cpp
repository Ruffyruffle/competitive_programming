#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

    long long int gs, cs = 1, ms, cuts;
    bool d = false;

int main(){

    cin>>gs>>ms;

    while (!d){
        //cout<<cuts<<"\n"<<gs<<"\n"<<ms<<"\n"<<cs<<"\n";
        if (cs >= gs){
            cout<<cuts;
            d = true;
        }
//        if (cs >= ms)
//            d = true;
//        }
        if (cs <= ms){
            cs += cs;
            cuts++;
        }
        else{
            cuts += ceil((gs-cs+ms-1)/ms);
            cs = gs;
        }
    }
//        else if (ms < cs){
//            cs+=ms;
//            cuts++;
//        }
//    cuts += ceil((gs-cs)/ms)
//    cout<<cuts;

    return 0;
}
