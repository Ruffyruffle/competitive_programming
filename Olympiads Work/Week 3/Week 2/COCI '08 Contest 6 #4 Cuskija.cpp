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
int n;
vector<int>a[3];

bool print(int c){
    if (a[c].size()!= 0){
        cout<<a[c].back()<<" ";
        a[c].pop_back();
        return 1;
    }
    return 0;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int b;
    for (int i =0; i < n; i++){
        cin>>b;
        a[b%3].push_back(b);
    }
    if (a[0].size() > a[1].size() + a[2].size()+1
        || (a[0].size() == 0 && a[1].size() != 0 && a[2].size() !=0)){
            cout<<"impossible";
            return 0;
        }
    if (a[0].size() > 1)
        print(0);
    while(a[1].size() > a[0].size() ){
        print(1);
    }
    while(a[0].size() !=0 && a[1].size()!=0){
        if (print(1)){
            print(0);
        }
    }
    while (print(2)){
        print(0);
    }
    if(a[2].size() > a[0].size() + 1){
        while(a[2].size() > a[0].size()){
            print(2);
        }
    }
    print(0);
}
