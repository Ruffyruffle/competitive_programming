#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    if (a < b)
        cout<<b-a;
    else
        cout<<min(a%b, b -(a%b));
}
