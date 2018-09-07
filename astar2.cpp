#include<iostream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 50

int currentX, currentY;
int goalX, goalY;
int opens = 0;
int l,w;
//ready nodes

class node{
    public:
        int g,h,f; // g = dist from start, est, sum
        bool inac, open, closed;
        int parentX, parentY;

    //set goal before using
    void ha(int x, int y){
        h = abs(goalX-x) + abs(goalY - y);
    }
    void init(int x, int y){
        g = 0x3f3f3f3f;
        f = 0x3f3f3f3f; // g = dist from start, est, sum
        inac = true;
//        if (open){
//          open=false;
//          opens--;
//        }
        open=false;
        closed=false;
    }
};
/// I DON'T THINK THESE ARE BEING INITIALIZED; USE STRUCTS TO DO SO
node nodes [MAXN][MAXN];

void calc(int x, int y){
        if (nodes[x][y].closed == true||nodes[x][y].inac == true)
        {
            int b;
        }
        else if (nodes[x][y].g>(nodes[currentX][currentY].g)+1 || nodes[x][y].open==false){
            nodes[x][y].g = (nodes[currentX][currentY].g)+1;
            //h = abs(goalX-x) + abs(goalY - y);
            nodes[x][y].f = nodes[x][y].g+nodes[x][y].h;
            nodes[x][y].parentX = currentX;
            nodes[x][y].parentY = currentY;
            if (!nodes[x][y].open){
            nodes[x][y].open = true;
            opens++;
            }
        }
    }
  //only use this on current
  void calcNei(int x, int y){
      calc(x+1,y);
      calc(x-1,y);
      calc(x,y+1);
      calc(x,y-1);
    }


int aStar(){
//keep count of open
    while(opens!=0){
        int least = 0x3f3f3f3f;
        //search for lowest fcost and set to current
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                if (nodes[i][j].open)
                    if(nodes[i][j].f < least){
                        least = nodes[i][j].f;
                        currentX = i;
                        currentY = j;
                        if (nodes[i][j].open){
                        nodes[i][j].open = false;
                        opens--;
                        }
                        nodes[i][j].closed = true;
                    }
            }
        }
        //calc nei
        calcNei(currentX, currentY);
        //break if current is goal
        if (currentX == goalX && currentY == goalY)
            return nodes[goalX][goalY].g;
    }
    return nodes[goalX][goalY].g;
}
void initAll(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            nodes[i][j].init(i,j);
        }
    }
}

void initGrid(int l,int w){
    initAll();
    for(int i = 0; i < l; i++){
        for(int j = 0; j < w; j++){
            char a;
            cin>>a;
            if (a == 'O')
                nodes[i][j].inac=false;
            else if (a == 'C'){
                currentX = i;
                currentY = j;
            }
            else if (a == 'W'){
                goalX = i;
                goalY = j;
            }
        }
    }
    nodes[currentX][currentY].open = true;
    opens++;
    calc(currentX,currentY);
    nodes[currentX][currentY].g = 0;
    calcNei(currentX,currentY);

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            nodes[i][j].ha(i,j);
        }
    }
}

int main(){
//set goal
    cin>>l>>w;
    initGrid(l,w);
    cout<<aStar();
}
