#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
int a, b;


return 0;
}

int * sieve(int n){
    int prime [500];
    int notPrime [500];
    for (int i = 2; i < n+1; i++){
        int c = find(begin(prime), end(prime), i);
        if (c != end(prime)){
            prime[i] = i;
        }
        for (int j = i*i; i < n+1; j+i){
            notPrime[j] = j;
        }
    }
    return prime;
}
