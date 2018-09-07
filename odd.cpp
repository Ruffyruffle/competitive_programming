#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int main() {
    int n,a,b = 0;
    cin>>n;
    for(int i = 0; i<n;i++){
        cin>>a;
        b = b^a;
    }
    cout<<b;
}
