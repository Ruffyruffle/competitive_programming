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
#define MAXN 51
using namespace std;
int r,c,n;
int sx,sy,ox,oy;
bool room[MAXN][MAXN];
int dis[MAXN][MAXN];

void solve(){
    char g;
    cin>>c>>r;
    MEM(room,false);
    for (int i =0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>g;
            room[i][j] = (g=='O');
            if (g=='C'){
                room[i][j] = true;
                sx = i; sy = j;
            }
            else if(g=='W'){
                room[i][j] = true;
                ox=i; oy = j;
            }
        }
    }
    MEM(dis,-1);
    int curx = sx; int cury = sy;
    queue<int> x,y;
    dis[curx][cury] = 0;
    x.push(sx); y.push(sy);
    while(!x.empty()){
        curx = x.front(); cury = y.front();
        if(curx == ox && cury == oy){
            if(dis[ox][oy] < 60)
                cout<<dis[ox][oy] <<endl;
            else
                cout<<"#notworth"<<endl;
            return;
        }

        if(curx != 0 && room[curx-1][cury] && dis[curx-1][cury]==-1){
            int nx = curx-1;
            dis[nx][cury] = dis[curx][cury] + 1;
            x.push(nx); y.push(cury);
        }
        if(curx != r-1 && room[curx+1][cury] && dis[curx+1][cury]==-1){
            int nx = curx+1;
            dis[nx][cury] = dis[curx][cury] + 1;
            x.push(nx); y.push(cury);
        }
        if(cury != 0 && room[curx][cury-1] && dis[curx][cury-1]==-1){
            int ny = cury-1;
            dis[curx][ny] = dis[curx][cury] + 1;
            x.push(curx); y.push(ny);
        }
        if(cury != c-1 && room[curx][cury+1] && dis[curx][cury+1]==-1){
            int ny = cury+1;
            dis[curx][ny] = dis[curx][cury] + 1;
            x.push(curx); y.push(ny);
        }
        x.pop(); y.pop();
    }
    cout<<"#notworth"<<endl;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        solve();
    }
}
