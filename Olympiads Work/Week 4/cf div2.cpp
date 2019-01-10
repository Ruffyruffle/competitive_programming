#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define x first
#define y second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1001
using namespace std;
int n,m,ans,k;
int d[MAXN][MAXN];
pii lead[MAXN][MAXN];
vector<int> x,y;
vector<pii> an;

int solve(pii cur, int c){
    MEM(d,INF);
    d[cur.f][cur.s] = 0;
    queue<pii> q;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int i = 1; i >= -1; i--){
            for(int j = -1; j <= 1; j++){
                if(i!= 0 && j != 0) continue;
                if(cur.f + i > 1000 || cur.f + i < 0 || cur.s + j > 1000 || cur.s + j < 0) continue;
                if(d[cur.f + i][cur.s + j] == INF){
                    d[cur.f + i][cur.s + j] = d[cur.f][cur.s] + 1;
                    q.push({cur.f + i, cur.s + j});
                }
            }
        }
    }
    if(c == 0){
        return d[x[1]][y[1]] + d[x[2]][y[2]];
    }
    else{
        return (c==1 ? d[x[0]][y[0]] + d[x[2]][y[2]] : d[x[1]][y[1]] + d[x[0]][y[0]]);
    }
}
void bfs(pii cur, int ans){
    MEM(d,INF);
    for(int i = 0; i <=1000; i++){
        for(int j = 0; j <= 1000; j++){
            lead[i][j] = {-1,-1};
        }
    }
    d[cur.f][cur.s] = 0;
    queue<pii> q;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        priority_queue<piii, vector<piii>, greater<piii> > pri;
        for(int i = 1; i >= -1; i--){
            for(int j = -1; j <= 1; j++){
                if(i!= 0 && j != 0) continue;

                if(cur.f + i > 1000 || cur.f + i < 0 || cur.s + j > 1000 || cur.s + j < 0) continue;
                pri.pb({abs(x[ans] - cur.x + i) + abs(i,y[ans] - cur.y + j), {cur.x+i, cur.y + j}});

            }
        }

        while(!pri.empty()){
            int xx = pri().front.s.f; int yy = pri().front().s.s;
            if(d[xx][yy] == INF){
                    lead[xx][yy] = cur;
                    d[xx][y] = d[cur.f][cur.s] + 1;
                    q.push({xx, yy});
                }
        }

    }

    MEM(d,INF);
    if(ans == 0){
        cur = {x[1],y[1]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
        cur = {x[2],y[2]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
    }

    else if(ans == 1){
        cur = {x[0],y[0]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
        cur = {x[2],y[2]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
    }
    else{
        cur = {x[0],y[0]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
        cur = {x[1],y[1]};
        while(cur.x != -1){
            if(d[cur.f][cur.s] == INF){
                an.pb({cur});
                d[cur.f][cur.s] = 1;

            }
            cur = lead[cur.f][cur.s];
        }
    }

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 0 ; i  <3; i++){
        int a,b;
        cin>>a>>b;
        x.pb(a); y.pb(b);
        d[a][b] = 0;
    }
    int ans = 0, mn = INF;
    int t = solve({x[0],y[0]}, 0);
    if(t < mn){
        mn = t;
        ans = 0;
    }
    t = solve({x[1],y[1]}, 1);
    if(t < mn){
        mn = t;
        ans = 1;
    }
    t = solve({x[2],y[2]}, 2);
    if(t < mn){
        mn = t;
        ans = 2;
    }
    bfs({x[ans],y[ans]}, ans);

    cout<<an.size()<<endl;
    for(pii i : an){
        cout<<i.f<<" "<<i.s<<endl;
    }

}
