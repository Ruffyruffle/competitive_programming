#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iomanip>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 10000

using namespace std;

struct point{
    int x,y;
};

point p[MAXN];

ld area(point p1, point p2, point p3){
    return((((p2.x * p3.y) - (p3.x * p2.y)) - ((p1.x * p3.y) - (p3.x * p1.y)) + ((p1.x * p2.y) - (p2.x * p1.y)))/2);

}

int ccw(point p1,point p2,point p3){
    int a = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    if (a==0) return 0;
    return (a>0)?2:1;
    //coll if 0, ccw if 1, cw if 2
}

int sqD(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

void exchange(point &a, point &b){
    point c = a;
    a = b;
    b = c;
}

//void graSort(&point p[], int n){
//    for (int i = 1; i < n-1; i++){
//        if
//
//
//    }
//
//
//}
point pL;

int distC(point p1, point p2){
    ld da = (pL.x - p2.x)*(pL.x - p2.x) + (pL.y - p2.y)*(pL.y - p2.y);
    ld db = (pL.x - p1.x)*(pL.x - p1.x) + (pL.y - p1.y)*(pL.y - p1.y);
    return(da>=db) ? -1:1;
}

int polarAngle(const void *p11,const void *p22){

    point *p1 = (point *)p11;
    point *p2 = (point *)p22;

    int a = ccw(pL,*p1,*p2);
    if (a==0)
        return distC(*p1,*p2);
    else
        return(a==2) ? -1:1;

// return -(x - x1) / (y - y1);

}
point next(stack<point> &s){
    point a = s.top();
    s.pop();
    point b = s.top();
    s.push(a);
    return b;
}

stack<point> graham(int n, point p[]){
    //bottom point
    int smy = p[0].y, small = 0, y;
    for (int i = 1; i < n; i++){
        y = p[i].y;
        if (smy > y){
            //cout<<y;
            smy = y, small = i;
        }
        else if (smy == y && p[i].x < p[small].x)
            smy = y, small = i;
    }
    //pLace at 0
    exchange(p[0],p[small]);
    pL = p[0];

    //cout<<p[0].x;
    //for (int i = 0; i < n; i++) cout<<p[i].x<<p[i].y<<endl;

    qsort(&p[1],n-1,sizeof(point),polarAngle);

    //for (int i = 0; i < n; i++) cout<<p[i].x<<p[i].y<<endl;
//    stack<point> sa;
//    for (int i = 0; i < n; i++){
//        sa.push(p[i]);
//    }
//    return sa;

    int siz = 1;
    for(int i = 1; i < n; i++){
        while (i < n-1 && ccw(pL,p[i], p[i+1]) == 0) i++;
        p[siz] = p[i];
        siz++;
    }
    //cout<<siz;
    stack<point> s;
    for(int i = 0; i < 3; i++) s.push(p[i]);

    for (int i = 3; i < siz; i++)
   {
      while (ccw(next(s), s.top(), p[i]) != 2) s.pop();
      s.push(p[i]);
   }

   return s;
}
int main(){

    int n;
    cin>>n;
    for (int i = 0; i < n; i++) cin>>p[i].x>>p[i].y;

    stack<point> s = graham(n,p);
    int si = s.size();
    point p[si];

    for (int i = 0 ; i < si; i++){
        p[i] = s.top();
        s.pop();
    }

    //cout<<endl;
    //for (int i = 0 ; i < si; i++) cout<<p[i].x<<" " <<p[i].y<<endl;

    int a = 0, b = 1,c = 2;
    //best
    int ga = a,gb= b,gc= c;

//    for(int i = 0; i < si; i++){
//        for(int j = 0; j < si; j++){
//                for(int k = 0; k < si; k++){
//                    if (area(p[i],p[j],p[k]) > area(p[ga],p[gb],p[gc])){
//                        ga = i, gb = j, gc = k;
//                    }
//                }
//        }
//    }


    for(int i = 0; i < si; i++){
    while(1){
            while(area(p[a], p[b], p[(c+1)%si]) >= (area(p[a],p[b],p[c]))){
                c = (c+1)%si;
            }
            if (area(p[a], p[(b+1)%si], p[c]) >= (area(p[a],p[b],p[c]))){
                b = (b+1)%si;
            }
            else
                break;
    }
    if (area(p[a],p[b],p[c]) > area(p[ga],p[gb],p[gc]) && a!=b && b!=c && a!=c){
            ga = a, gb = b, gc = c;
        }
        a+=1;
    }

    cout << fixed;
    cout << setprecision(3);
    cout<<area(p[ga],p[gb],p[gc]);
    //cout<<endl<<p[ga].x<<" "<<p[gb].x<<" "<<p[gc].x;
    //cout<<endl<<p[ga].y<<" "<<p[gb].y<<" "<<p[gc].y;
}





