#include <iostream>
using namespace std;

bool check(int n){
    if (n%2 == 0)
        return false;

    bool p = true;
    for(int i = 2; i <= n / 2; ++i)
         if(n % i == 0)
         {
             p = false;
             break;
         }
     return p;
}
int main(){
    int n;
    cin>>n;
    while(true){
        if (check(n) == true){
            cout<<n;
            break;
        }
        n++;
    }
}
