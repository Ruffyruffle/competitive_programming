#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ll n,m,k,ans;

struct line{int row,a,b;};
vector<int> rs,cols;
vector<line> sub;
//char dif[10001][20002];
vector<pii> dif[10001];
bool cmp(line a, line b){
    return a.b < b.b;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i =0,r,a,b; i < k; i++){
        cin>>r>>a>>b;
        sub.pb({r,a,b+1});
        rs.pb(r); cols.pb(a); cols.pb(b+1);
    }
    sort(rs.begin(), rs.end());
    sort(cols.begin(), cols.end());
    UNI(rs); UNI(cols);
    unordered_map<int,int> rkr,rkc,rkc2;
    for(int i = 0; i < rs.size(); i++){
        rkr[rs[i]] = i;
    }
    for(int i = 0; i < cols.size(); i++){
        rkc2[i] = cols[i];
        rkc[cols[i]] = i;
    }
    sort(sub.begin(),sub.end(),cmp);
    for(line i : sub){
        dif[rkr[i.row]].pb({rkc[i.a],1});
        dif[rkr[i.row]].pb({rkc[i.b],-1});
    }
    for(int i = 0; i < rs.size(); i++){
        sort(dif[i].begin(), dif[i].end());
    }

    int start, cnt= 0;
    for(int i = 0; i < rs.size(); i++){
        int cur = -1;
        for(int j = 0; j < dif[i].size(); j++){
            //cout<<rkc2[dif[i][j].f]<<endl;
            if(dif[i][j].f == cur){
                cnt+=dif[i][j].s;
                continue;
            }
            if(cnt>0&&j!=0){
                ans+=rkc2[dif[i][j].f] - rkc2[dif[i][j-1].f];
                //cout<<rkc2[dif[i][j].f];
                //cout<<rkc2[dif[i][j].f] - rkc2[dif[i][j-1].f]<<endl;
            }
            cnt += dif[i][j].s;
            cur = dif[i][j].f;
        }
    }
    cout<<n*m - ans;



}
