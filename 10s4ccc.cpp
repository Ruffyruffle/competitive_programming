#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {

int n;
cin>>n;

int points[9][2];

for (int i = 0; i < n; i++){
  cin>>points[i][0]>>points[i][1];
}

float longest;

for (int i = 0; i < n; i++){
  for (int j = 0; j < n; j++){
    float length = sqrt(pow(points[j][0] - points[i][0],2) + pow(points[j][1] - points[i][1],2));
    if (length > longest)
      longest = length;
  }
}

printf("%.2f", longest);
//cout<<longest;
return 0;
}
