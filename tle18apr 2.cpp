#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    double h;
    int d,e;
    cin>>h>>d>>e;
    double ai[d], si[d], tj[e], lj[e], xj[e];
    for (int i = 0; i < d; i++) cin>>ai[i]>>si[i];
    for (int i = 0; i<e; i++) cin>>tj[i]>>lj[i]>>xj[i];

    for (int i = 0; i < d;i++){
        (ai[i] = 1 - ai[i]*0.01);
        //cout << ai[i] << " ";
    }

    double damage[1000];
    memset(damage, 0, sizeof(damage));
    for (int j = 0; j<e; j++){
        for (int i = tj[j]; i < (lj[j]+tj[j]); i++){
            damage[i] += xj[j];
            //cout<< damage[i] << " ";
        }
    }


    double mi = 0x3f3f3f3f;
    for (int i = 0; i < 999; i++){
        if (damage[i] !=0){
            mi = 0x3f3f3f3f;
            if (d == 0)
                mi = damage[i];
            else{
                for (int j = 0; j<d; j++){
                    if ((damage[i] - si[j]) * ai[j] < mi){
                        mi = (damage[i] - si[j]) * ai[j];
                        //cout<< si[j] << " ";
                       // if (mi < 0)
                        //    mi = 0;
                        //cout << mi << " ";
                    }

                }
            }
            //printf("%.2f", 99 * 0.99);
            if (mi == 0){
                mi = 0;
            }
            h -= mi;
        }


    }
    if (0>=h)
        cout<<"DO A BARREL ROLL!";
    else
        printf("%.2f", h);



}
