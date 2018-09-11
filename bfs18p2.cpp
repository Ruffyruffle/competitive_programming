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
string m;
int n;
int ch = 0;
int let[26][MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    //getline(cin, m);
    //cin>>n;
    int a,b;
    char c;
    MEM(let, 0);
    //std::replace(m.begin(), m.end(), ' ', '{');
    //int l = (int)m.length();
    //char d;
    while(1){
        cin>>m;
        if(isdigit(atoi(m.c_str())))
        {
            n = stoi(m);
            break;
        }
        else{
            for(int l = 0; l < m.length(); l++){
                for(int j = 0; j <= ch; j++){
                    let[static_cast<int>(m[l]) - 97][j]++;
                    ch++;
                }
            }
        }

    }

    for (int i =0; i < n; i++){
        cin>>a>>b>>c;
        cout<<let[static_cast<int>(c) - 97][a] - let[static_cast<int>(c) - 97][b]<<endl;
    }
}
