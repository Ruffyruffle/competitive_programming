#include<iostream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
int state[MAXN][MAXN];
// 0 = no set
//1 = open
//2 = closed
int score[MAXN][MAXN][3];
/* 0 = gscore
1 = hscore
2 = fscore (cost)*/
//0 = x
//1 = y
//int cost[MAXN][MAXN];
struct point{
    int x;
    int y;
};

point parent[MAXN][MAXN];
point current;
point goal;

int fCost(point goal, point p1){
    int h = abs(goal.x-p1.x) + abs(goal.y - p1.y);
    return h + score[p1.x][p1.y][0];
}
void calc(point neighbour, point current){
    //if not closed and gcost<old gcost(infinite if not set yet(ie.no set))
    if (state[neighbour.x][neighbour.y] != 2 && (score[current.x][current.y][0]+1<score[neighbour.x][neighbour.y][0])){
        score[neighbour.x][neighbour.y][0] = score[current.x][current.y][0]+1;
        score[neighbour.x][neighbour.y][2] = fCost(goal, neighbour);
        parent[neighbour.x][neighbour.y] = current;
        state[neighbour.x][neighbour.y] = 1;
        }
}
void nei(point current){
    calc({current.x,current.y+1}, current);
    calc({current.x+1,current.y}, current);
    calc({current.x-1,current.y}, current);
    calc({current.x,current.y-1}, current);
}
void draw(){
  for (int i = 0; i < MAXN;i++){
    cout<<endl;
    for (int j = 0; j < MAXN; j++){
      //draw
      if (i == current.x && j == current.y)
        cout<<"C";
      else if (i == goal.x && j == goal.y)
        cout<<"G";
      else
        switch (state[i][j]){
    case 0:
        cout<<"N";
        break;
    case 1:
        cout<<"O";
        break;
    case 2:
        cout<<"X";
        break;
    default:
      cout<<"A";
        break;
        }
    }
  }
}
void drawstate(){
  for (int i = 0; i < MAXN;i++){
    cout<<endl;
    for (int j = 0; j < MAXN; j++){
      cout<<state[i][j];
    }
  }
}
int aStar(point current, int length, int height, point goal){
  score[current.x][current.y][0] = 0;
    //should be while open is not empty
    while (true){
    //cost compare all nei
        nei(current);
        //drawstate();
      int low = 0x3f3f3f3f;
        //set current to smallest f cost node in open
        for (int i = 0; i < length;i++){
                for (int j = 0; j < height; j++){
                    if (state[i][j] == 1)
                        if (score[i][j][2] < low){
                            low = score[i][j][2];
                            current.x = i;
                            current.y = j;
                        }
                }
        }
        cout<<current.x<<current.y;
        //set current to closed.
        state[current.x][current.y] = 2;
        //break if goal
        if (current.x == goal.x && current.y == goal.y)
            return score[current.x][current.y][2];
            break;
        if (score[current.x][current.y][0]>60){
            return 100;
        }
    }
    return score[current.x][current.y][2];
}

int dist(point p1,point p2){
    return sqrt(pow(p2.x-p1.x,2) + pow(p2.y - p1.y,2));
}
void setup(){
 memset(state, 2, sizeof(state[0][0]) * MAXN * MAXN);
 memset(score, 0x3f3f3f3f, sizeof(score[0][0][0]) * MAXN * MAXN * 3);
}
int main(){
    setup();
    int t,l,w;
    char a;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>l>>w;
        for(int j = 0; j < l; j++){
            for(int k = 0; k < w; k++){
                cin>>a;
                switch(a){
                    case 'O':
                        state[j][k] = 0;
                        break;
                    case 'C':
                        current = {j,k};
                        state[j][k] = 1;
                        break;
                    case 'W':
                        goal = {j,k};
                        state[j][k] = 0;
                        break;
                    case 'X':
                        score[i][j][2] = 0x3f3f3f3f;
                        break;
                }
            }
        }
        int b = aStar(current,w,l,goal);
        if (b>=60)
            cout<<b>=(60 ?"#notworth":b)<<endl;


    }

}
//https://dmoj.ca/problem/dmopc13c1p4
