#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 101
typedef std::pair<std::pair<int,int>,std::pair<int,int>> pii;
using namespace std;

int x,y,n,x1,yy,x2,y2;
int dp[MAXN][MAXN][32][32];
bool f[MAXN][MAXN];
int wind[MAXN][MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>x>>y>>n;
    cin>>x1>>yy>>x2>>y2;
    queue<pii> q;
    queue<int> times;
    int cx,cy,vx,vy,t;
    int a,b;
    while(n--){
        cin>>a>>b;
        f[a][b] = 1;
    }

    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[x1][yy][0][0] = 0;

    q.push({{x1,yy},{0,0}}); times.push(0);
    while(!q.empty()){
        cx = q.front().f.f; cy=q.front().f.s;
        vx=q.front().s.f; vy = q.front().s.s;
        q.pop();
        t=times.front(); times.pop();
        if(cx > x || 0 > cx || cy > y || 0>cy) continue;
        if(f[cx][cy]) continue;
        if(dp[cx][cy][vx+15][vy+15] <= t){
            continue;
        }
        else{
            dp[cx][cy][vx+15][vy+15] = t;
        }

        if(cx == x2 && cy == y2 && vx==0 && vy == 0){
            cout<<t<<endl; return 0;
        }

        if(15 > vx && vx>-15){
            bool can = 1;
            if(vx+1>0){
                for(int i = 1; i <= abs(vx+1); i++){
                    if(wind[cx+i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vx+1); i++){
                    if(wind[cx-i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
            if(can) q.push({{cx+vx+1, cy+vy},{vx+1,vy}}), times.push(t+1);
            can = 1;

            if(vx-1>0){
                for(int i = 1; i <= abs(vx-1); i++){
                    if(wind[cx+i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vx-1); i++){
                    if(wind[cx-i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
            if(can) q.push({{cx+vx-1, cy+vy},{vx-1,vy}}),times.push(t+1);
        }
        if(15>vy && vy >-15){
            bool can = 1;

            if(vy+1>0){
                for(int i = 1; i <= abs(vy+1); i++){
                    if(wind[cx][cy+i]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vy+1); i++){
                    if(wind[cx][cy-i]){
                        can = 0;
                        break;
                    }
                }
            }
            if(can) q.push({{cx+vx, cy+vy+1},{vx,vy+1}}), times.push(t+1);

            can = 1;

            if(vy-1>0){
                for(int i = 1; i <= abs(vy-1); i++){
                    if(wind[cx][cy+i]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vy-1); i++){
                    if(wind[cx][cy-i]){
                        can = 0;
                        break;
                    }
                }
            }
            if(can){
                    q.push({{cx+vx, cy+vy-1},{vx,vy-1}});
                    times.push(t+1);
            }
        }

        bool can = 1;
        if(vx>0){
                for(int i = 1; i <= abs(vx); i++){
                    if(wind[cx+i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vx); i++){
                    if(wind[cx-i][cy]){
                        can = 0;
                        break;
                    }
                }
            }
        if(vy>0){
                for(int i = 1; i <= abs(vy); i++){
                    if(wind[cx][cy+i]){
                        can = 0;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= abs(vy); i++){
                    if(wind[cx][cy-i]){
                        can = 0;
                        break;
                    }
                }
            }

        if(can)q.push({{cx+vx, cy+vy},{vx,vy}}),times.push(t+1);
    }
    cout<<-1<<endl;
}
