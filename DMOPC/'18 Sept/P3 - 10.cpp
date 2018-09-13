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
vector<int> op[10000];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a[n+1];
    for (int i =1; i < n+1; i++){
        cin>>a[i];
    }
    a[0] = 0;
    //cout<<"a";
    int o = 0;
    while(!is_sorted(a, a+(n+1))){
        for (int i =1; i < n+1; i++){
            if (a[i]!=i){
                op[o].push_back(2);
                op[o].push_back(a[i]);
                op[o].push_back(i);
                swap(a[i],a[a[i]]);
                o++;
            }
        }
    }
    cout<<o<<endl;
    for(int i = 0; i < o; i++){
        cout<<op[i][0]<<" " <<op[i][1]<<" " <<op[i][2]<<endl;
    }
}
