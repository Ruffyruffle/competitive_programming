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
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,m;
vector<int> l[27], r[27];
vector<int> lg,rg;
vector<pii> ans;
bool t[MAXN];
bool t2[MAXN];
vector<int> lr,rr;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n; string s;
    cin>>s;
    for (int i =1; i <= n; i++){
        if(s[i-1]=='?') lg.pb(i);
        else l[s[i-1]-'a'].pb(i);
    }
    cin>>s;
    for (int i =1; i <= n; i++){
        if(s[i-1]=='?') rg.pb(i);
        else r[s[i-1]-'a'].pb(i);
    }
    for(int i = 0; i < 26; i++){
        for(int j : l[i]){
            if(r[i].size() != 0){
                ans.pb({j, r[i][0]});
                t[j]=1;t2[r[i][0]]=1;
                r[i].erase(r[i].begin());
                continue;
            }
            if(rg.size() != 0){
                ans.pb({j,rg[0]});
                t[j]=1;t2[rg[0]]=1;
                rg.erase(rg.begin());
            }
        }
        for(int j : r[i]){
            if(t2[j]) continue;
            if(lg.size() != 0){
                ans.pb({lg[0],j});
                t2[j]=1;t[lg[0]]=1;
                lg.erase(lg.begin());
            }
        }
    }
    for(int i : lg){
        if(rg.size()!=0){
            ans.pb({i,rg[0]});
            rg.erase(rg.begin());
        }
    }
    for(int i : rg){
        if(lg.size() != 0){
            ans.pb({lg[0],i});
            lg.erase(lg.begin());
        }
    }
//    for(int i = 1; i <= n; i++){
//        if(!t2[i] && s[i-1] != '?') rr.pb(i);
//    }
//    for(int i : lg){
//        if(rr.size() != 0){
//            ans.pb({i, rr[0]});
//            t[i]=1;t2[rr[0]]=1;
//            rr.erase(rr.begin());
//            continue;
//        }
//        if(rg.size() != 0){
//            ans.pb({i,rg[0]});
//            t[i]=1; t2[rg[0]] = 1;
//            rg.erase(rg.begin());
//        }
//    }
//    for(int i = 1; i <= n; i++){
//        if(!t[i]) lr.pb(i);
//    }
//    for(int i : rg){
//        if(t2[i]) continue;
//        if(lr.size() != 0){
//            ans.pb({i, lr[0]});
//            lr.erase(lr.begin());
//        }
//    }
    cout<<ans.size()<<endl;
    for(pii i : ans){
        cout<<i.f<<" "<<i.s<<endl;
    }



}
