#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

  int floor, r,c, a = 0;
  char temp;
  int space [25][25];
  int room[625];
  //1 = wall
  //col, row

void recurSearch(int x, int y, int rnum){
  space[y][x] =1;
  room[rnum]++;
  if (x != 0)
    if (space[y][x-1] == 0)
      recurSearch(x-1, y, rnum);
  if (y != 0)
    if (space[y-1][x] == 0)
      recurSearch(x, y-1, rnum);
  if (x != r-1)
    if (space[y][x+1] == 0)
      recurSearch(x+1, y, rnum);
  if (y != c-1)
    if (space[y+1][x] == 0)
      recurSearch(x, y+1, rnum);
}

int main() {
    cin>>floor>>r>>c;
    memset(space, 0, sizeof(space));
    for(int j = 0; j < r; j++){
        for(int i = 0; i < c; i++){
      //cout<<i;
          cin>>temp;
          if (temp == 'I')
            space[i][j] = 1;
        }
    }
//    for(int j = 0; j < r; j++){
//        cout<<endl;
//        for(int i = 0; i < c; i++) cout<<space[i][j];
//    }
    bool done = false;

    for(int j = 0; j < r; j++){
      for(int i = 0; i < c; i++){
        if (space[i][j] == 0)
          recurSearch(j,i,a);
          a++;
      }
    }

    sort(room, room + 625);
    int ans = 0;
    for (int i = 625; i >= 0; i--){
        if (room[i] != 0){
            if (floor >= room[i]){
                floor -= room[i];
                ans++;
            }
            else
                break;
        }
    }
    if (ans!=1)
        cout<< ans<<" rooms, "<<floor<<" square metre(s) left over";
    else
        cout<< ans<<" room, "<<floor<<" square metre(s) left over";
}
