#include <iostream>
using namespace std;

int main() {
int a, e;
string b[a];
string c;
cin>>a;
for (int i = 0; i < a; i++) cin>>b[i];
for (int i = 0; i < a; i++){
    cin>>c;
    if (c == b[i])
        e++;
}
cout<<e;
}
