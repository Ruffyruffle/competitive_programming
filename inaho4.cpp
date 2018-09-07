#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
int n;
cin>>n;

double points[2][n];

for(int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
                cin>>points[j][i];
        }
}

double a;
for (int i = 0; i < n; i++) a += pow((points[0][i]) - (points[1][i]),2);

cout<<setprecision(30)<<sqrt(a);
return 0;
}
