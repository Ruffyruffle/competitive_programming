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
#define MAXN 1000000
using namespace std;
int n,p=0;
string a,b;

int main(){

    getline(cin, a);
    getline(cin, b);
    cin>>n;
    while(a.length() > b.length()){
        b += ' ';
    }
    while(b.length() > a.length()){
        a += ' ';
    }
    for (int i =0; i < a.length(); i++){
        if(a[i]==' ')
            if(b[i] != ' '){
                p = 10000;
                break;
            }
        if(b[i]==' ')
            if(a[i] != ' '){
                p = 100000;
                break;
            }
        if (a[i] != b[i]){
            p++;
        }
    }
    //cout<<a<<endl<<b;
    if (p<=n)
        cout<<"Plagiarized";
    else
        cout<<"No plagiarism";
}
