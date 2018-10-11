#include<stdio.h>
#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    double x,y,x1,y1,a = 250*125;
    cin>>x>>y;
    if(x == 0 && y==0){ x1 = 125.00; y1 = 125.00; }
    else if (x ==0){
        if (y < 125){
            x1 = a/(250-y); y1 = 250-x1;
        }
        else{
            x1 = a/y; y=0;
        }
    }
    else if(y==0){
        if(x<125){
            y1 = a/(250-x); x1 = 250-y1;
        }
        else{
            x1 = 0; y1 = a/x;
        }
    }
    else if (x<125){
        x1 = 250-a/y; y1 = 0;
    }
    else if (x>125){
        x1 = 0; y1 = 250-a/x;
    }
    cout<<fixed;
    cout<<setprecision(2);
    cout<<x1<<" " <<y1;
}
