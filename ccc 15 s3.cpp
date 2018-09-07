#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int g, p;
  cin>>g>>p;

  bool dc[p];
  bool aa = false;
  memset(dc, true, sizeof(dc));
  int pd;
  bool t;

  for(int i = 0; i < p; i++){
    cin>>pd;
    t = true;
    for(int j = min(pd,g); j > 0; j--){
      if(dc[j]){
        dc[j] = t = false;
        break;
      }
    }
    if(t){
      cout<<i;
      aa = true;
      break;
    }
  }
  if(!aa)
    cout<<g;
}
