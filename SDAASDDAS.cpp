#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a, b, c, d;
    cin>>a>>b;
    float q = b/a;
    int w = b-a;
    bool g = true;



    for (int i = 0; i < n-1; i++){
        cin >> c >> d;
        float f = d/c;
        if (f != q && d-c != w)
            g = false;


    }



    if (g)
        cout<<"yes";
    else
        cout<<"no";



}
//#include<iostream>
//#include <stdio.h>
//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int a, b, c, d;
//    cin>>a>>b;
//    float q = b/a;
//    bool g = true;
//    for (int i = 0; i < n-1; i++){
//        cin >> c >> d;
//        if (d/c != q)
//            g = false;
//    }
//    if (g)
//        cout<<"yes";
//    else
//        cout<<"no";
//
//
//
//}
