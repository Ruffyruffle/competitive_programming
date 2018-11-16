#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
int a[6];

int main(){
    for(int i = 0; i < 6; i++){
        cin>>a[i];
        a[i] = sqrt(a[i]);
    }
    for(int i = 0; i < 3; i++){
        if(a[i] != a[i+3]){
            cout<<"Colourful";
            return 0;
        }
    }
    cout<<"Dull";
}
