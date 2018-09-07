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
#define MAXN 1000000;
using namespace std;

int main(){

    string a;
    char b;
    int n,c,ans=0,f,j;
    cin>>n>>j;
    for(int i =0;i<n;i++){
        cin>>b;
        a+=b;
    }
    for(int i =0;i<j;i++){
        cin>>b>>c;
        if (a[c-1] != 'X' && n>=c){
            if(b == 'S'){
                ans++;
                a[c-1] = 'X';
            }
            else if (b== 'M'){
                if (a[c-1]!='S'){
                    ans++;
                    a[c-1] = 'X';
                }
            }
            else if (b== 'L'){
                if (a[c-1] == 'L'){
                    ans++;
                    a[c-1] = 'X';
                }
            }
        }

    }
    cout<<ans;
}
