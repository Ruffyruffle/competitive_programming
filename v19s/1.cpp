#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<string, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 10002
int n,m,ans;
vector<piii> a; //n,vote,order
vector<int> v[MAXN];
vector<pii> vi[23];
bool exist[23];

bool cmp(piii a, piii b){
    if(a.s.f == b.s.f){
        return a.s.s < b.s.s;
    }
    return a.s.f < b.s.f;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m; string s;
    unordered_map<string,int> o;
    for (int i =0; i < n; i++){
        cin>>s;
        a.pb({s,{0,i}});
        o[s]=i;
    }
    for(int i = 0,x; i < m; i++){
        cin>>x;
        for(int j = 0; j < x; j++){
            cin>>s;
            v[i].pb(o[s]);
        }
        vi[v[i][0]].pb({i,0});
        a[v[i][0]].s.f++;
        //cout<<a[v[i][0]].f<<endl;
    }
    while(a.size() > 1){
        sort(a.begin(),a.end(),cmp);
//        for(piii i : a){
//            cout<<i.f<<" "<<i.s.f<<endl;
//        }
//        cout<<endl;
        int elim = a[0].s.s;
        //cout<<a[0].f<<" "<<a[0].s.f<<" "<<endl;
        exist[elim] = 1;
        for(pii &i : vi[elim]){
            if(v[i.f].size()-1 <= i.s) continue;
            i.s++;
            int in = v[i.f][i.s];
            while(exist[in] && v[i.f].size()-1 > i.s){
                in = v[i.f][i.s+1];
                i.s++;
            }
            //cout<<in<<endl;
            for(piii &j : a){
                if(j.s.s == in) j.s.f++;
            }
            vi[in].pb({i.f, i.s});
        }
        a.erase(a.begin());
    }
    while(a.size() > 1){
        sort(a.begin(),a.end(),cmp);
    }
    cout<<a[0].f;
}
