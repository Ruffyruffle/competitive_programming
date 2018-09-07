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
int x,y;
int dir = 1;
int spiral[12][12];
string asd[12];
string asdd[12];
void print(int step){
    int xmin = 12, xmax = 0, ymax = 0, ymin = 12;
    for(int i = 0; i<12; i++){
        for(int j = 0; j<12; j++){
                if (spiral[j][i]!=-1){
                    if (j > xmax)
                       xmax = i;
                    if (j < xmin)
                       xmin = i;
                    if (i > ymax)
                        ymax = i;
                    if (i < ymin)
                        ymin = i;

                }
        }
    }

    for(int i = ymin; i<ymax + 1; i++){
        for(int j = xmin; j<xmax+1 ; j++){
                //spiral[j][i]!=-1 ? cout<<spiral[j][i]<< " ": (spiral[j][i]>9) ? cout<<"   " : cout<<"  ";
            if (spiral[j][i]!=-1){
                spiral[j][i] > 9 ? asd[i] += to_string(spiral[j][i]) : asd[i] += " " + to_string(spiral[j][i]);
                asd[i] += " ";
            }
            else asd[i] += "   ";
        }
    }
    if (asd[5][0] == ' '){
        for(int i = 0; i<12; i++){
            if (!asd[i].empty())
                asd[i].erase(0, 3);
        }
    }

    for(int i = 0; i<12; i++){
        if (!asd[i].empty())
            cout<<asd[i]<<endl;
    }
}

int main(){

    cin>>x>>y;
    int n = y-x;


    MEM(spiral,-1);


    int a = 5, b = 5;
    spiral[a][b] = x;
    int coun = 1;
    int step = 1;
    b+=1;
    spiral[a][b] = x+1;
    y++;
    for (int i = x+2; i <y; i=i){
        coun++;
        int z = step*step;
        //for each step,


        if (i == y)
            print(step);
        for(int j = 0; j<2*step-1; j++){
            a+=1;
            spiral[a][b] = i;
            i++;
            if (i == y)
                print(step);
        }
        for(int j = 0; j<2*step; j++){
            b-=1;
            spiral[a][b] = i;
            i++;
            if (i == y)
                print(step);
        }
        for(int j = 0; j<2*step; j++){
            a-=1;
            spiral[a][b] = i;
            i++;
            if (i == y)
                print(step);
        }
        for(int j = 0; j<2*step+1; j++){
            b+=1;
            spiral[a][b] = i;
            i++;
            if (i == y)
                print(step);
        }
        step++;
    }
}
