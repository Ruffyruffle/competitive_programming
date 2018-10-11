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
int n,m,k, ans = 0;
int s[1001][MAXN];
//queue<int> q;
void stand(int x, int y){

    ans++;
    if(x!=0){
        if(s[x - 1][y]!= -1){
            s[x-1][y]++;
        if (s[x-1][y] == 2)
            stand(x-1, y);
        }
    }

    if(s[x+1][y]!= -1){
        s[x+1][y]++;
    if (s[x+1][y] == 2)
        stand(x+1, y);
    }

    if(s[x][y+1]!= -1){
        s[x][y+1]++;
    if (s[x][y+1] == 2)
        stand(x, y+1);
    }

    if(y!=0){
        if(s[x][y-1]!= -1){
            s[x][y-1]++;
        if (s[x][y-1] == 2)
            stand(x, y-1);
        }
    }

}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>k;
    int x,y;
    MEM(s, -1);
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            s[i][j] = 0;
        }
    }
    for (int i =0; i < k; i++){
        cin>>x>>y;
        s[x-1][y-1] = 2;
        stand(x-1,y-1);
    }

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    cout<<ans;
}

