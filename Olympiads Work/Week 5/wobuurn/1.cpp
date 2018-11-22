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
#define MAXN 50001
using namespace std;
int n;
int r,c;
int ans =0;
int d[11][MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c>>n;
    for (int i =0; i < c; i++){
        for(int j = 0; j < r; j++){
            cin>>d[i][j];
        }
    }
    int cou;
    for(int j = 0; j < c; j++){
        cou = 0;
        for(int i = 0; i < r; i++){
            cou--;
            if(d[j][i] == 1)
                cou = n+1;
            else if(d[j][i] == 2 && cou > 0){
                ans++;
            }
        }
    }
    cout<<ans;
}
