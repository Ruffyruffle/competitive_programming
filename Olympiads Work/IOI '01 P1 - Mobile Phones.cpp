#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1025
using namespace std;
int n,x,y,x2,y2,v,d;
int bit[MAXN][MAXN];
void add(int i,int j,int val){
    int t = j;
    while(i <= n){
        while(j<= n){
            bit[i][j] += val;
            j+=(-j&j);
        }
        i+=(-i&i);
        j = t;
    }
}

int sum(int i, int j){
    int ans = 0, t = j;
    while(i > 0){
        while(j>0){
            ans+=bit[i][j];
            j-=(j&-j);
        }
        i-=(i&-i);
        j = t;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>n;
    while(cin>>d){
        if (d == 1){
            cin>>x>>y>>v;
            add(x+1,y+1,v);
        }
        else if (d==2){
            cin>>x>>y>>x2>>y2;
            cout<<(sum(x2+1,y2+1) - sum(x, y2+1) - sum(x2+1,y) + sum(x,y))<<endl;
        }
        else if(d==3){ break; }
    }
}
