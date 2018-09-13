#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 100
using namespace std;
int n,k;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin>>a[i];
    }
    for (int i =1; i < n+1; i++){
        if ((abs(a[i] - i) % k) !=0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
