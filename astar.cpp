#include<iostream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 50

int currentX, currentY;
int goalX, goalY;
node nodes [MAXN][MAXN];
int opens = 0;
//ready nodes
void initAll(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            nodes[i][j].init();
        }
    }
}

class node{
    private:
        int g,h,f; // g = dist from start, est, sum
        bool inac, open, closed;
        int parentX, parentY;

    void calc(int x, int y){
        if (closed == true||inac == true)
        {
            break;
        }
        if (g>(nodes[currentX][currentY].g)+1 || open==false){
            g = (nodes[currentX][currentY].g)+1;
            //h = abs(goalX-x) + abs(goalY - y);
            f = g+h;
            parentX = currentX;
            parentY = currentY;
            open = true;
        }
    }
    //only use this on current
    void calcNei(int x, int y){
        nodes[x+1][y].calc(x+1,y);
        nodes[x-1][y].calc(x-1,y);
        nodes[x][y+1].calc(x,y+1);
        nodes[x][y-1].calc(x,y-1);
    }
    //set goal before using
    void init(){
        g = 0x3f3f3f3f;
        h = abs(goalX-x) + abs(goalY - y);
        f=0; // g = dist from start, est, sum
        inac = true;
        open=false;
        closed=false;
    }
};
int aStar(){
    //keep count of open
    while(open!=0){
        int least = 0x3f3f3f3f;
        //search for lowest fcost and set to current
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                if (nodes[i][j].open)
                    if(nodes[i][j].f < least){
                        least = nodes[i][j].f;
                        currentX = i;
                        currentY = j;
                        nodes[i][j].open = false;
                        nodes[i][j].closed = true;
                    }
            }
        }
        //break if current is goal
        if (currentX == goalX && currentY == goalY)
            return nodes[goalX][goalY].g;
        //calc nei
        nodes[currentX][currentY].calcNei(currentX, currentY);
    }
    return nodes[goalX][goalY].g;
}
void initGrid(int l,w){
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
                nodes[i][j].open = true;
                nodes[i][j].calc([i][j]);
                nodes[i][j].g = 0;
                nodes[i][j].calcNei();
            }
            else if (a == 'W'){
                goalX = i;
                goalY = j;
            }
        }
    }
}
int main(){
//set goal
    int l,w;
    cin>>l>>w;
    initGrid(l,w);
    aStar();
}
