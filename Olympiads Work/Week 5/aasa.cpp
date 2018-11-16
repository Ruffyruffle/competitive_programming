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
#define MAXN 101
using namespace std;
int n;
vector<vector<int>> p;
vector<pair<int, int> >a[MAXN];
vector<int> ans[MAXN][MAXN];
bool visited[MAXN];

void findPaths(int cur, int des, int *path, int &pi, int dist){
    visited[cur] = true; path[pi] = dist; pi++;
    if(cur == des){
        vector<int> t(path, path+pi);
        p.pb(t);
        for(int i = 0; i < pi; i++){
            cout<<path[i] << " ";
        }
        cout<<endl;
    }
    else{
        for(int i = 0; i < a[cur].size(); i++){
            if(!visited[a[cur][i].first])
                findPaths[a[cur][i].first, des, visited, path, pi, a[cur][i].second];
        }
    }
    pi--; visited[cur] = false;
}

int solve(int i){
    int ans = INF;
    for(int j = 0; j <p.size(); j++){
        int lo = INF, hi = -1;
        for(int k = 0; k < p[j].size(); k++){
            if (p[j][k] < lo)
                lo = p[j][k];
            if(hi < p[j][k])
                hi = p[j][k];
        }

        while(lo <= hi){
            int mid = (lo+hi) / 2;
            int r = 1, t = 0;
            for(int i = 0; i < n; i++){
                if (t + p[j][i] > mid){
                    t = 0;
                    r++;
                }
                t += p[j][i];
            }
            bool ff = (i >= r);
            if(ff){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        ans = min(lo, ans);
    }
    if (ans == INF) ans = 0;
    return ans;
}

vector<int> solveSegs(int start, int des){
    p.clear();
    int path[n];
    MEM(path, 0);
    int pi = 0;
    MEM(visited, false);

    findPaths(start, des, path, pi, 0);

    vector<int> ans;
    ans.pb(0);
    for(int i = 1; i < n; i++){
        ans.pb(solve(i));
    }
    return ans;
}

void preComp(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans[i][j] = solveSegs(i,j);
        }
    }
}

int main(){
    cin>>n;
    int x, q;
    for (int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>x;
            if(x!='0'){
                a[i].pb(make_pair(j,x));
            }
        }
    }
    preComp();
    cin>>q;
    int s,t,d;
    for(int i = 0; i < q; i++){
        cin>>s>>t>>d;
        cout<<ans[s][t][d];
    }




}
