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
#define MAXN 100001
using namespace std;
int n;
int a[MAXN], b[MAXN], DP[MAXN], s = 0;
int c[MAXN];

int main(){
    cin>>n;
    for (int i =0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
        c[i] = a[i] - b[i];
        s+=b[i];
    }
    if (n >= 1){
        if(c[0] > 0)
            DP[0] = c[0];
        else
            DP[0] = 0;
    }
    if (n >= 2){
        if(c[1] > 0)
            DP[1] = DP[0] + c[1];
        else
            DP[1] = DP[0];
    }
    if(n >= 3){
        if(c[2] > 0)
            DP[2] = max(max(c[1] + c[2], DP[1]), DP[0] + c[2]);
        else
            DP[2] = DP[1];
    }

    for(int i = 3; i < n; i++){
        if(c[i]>0){
            DP[i] = max(max(DP[i-2] + c[i], DP[i-1]), c[i] + c[i-1] + DP[i-3]);
        }
        else{
            DP[i] = DP[i-1];
        }
    }
    cout<<DP[n-1] + s;
}
