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
typedef std::pair<pii, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 500002
using namespace std;
int n,m,ans;
vector<string> a[MAXN],b[MAXN];
vector<pair<string,piii>> c;

bool cmp(pair<string,piii> a, pair<string,piii> b){
    return a.f == b.f;
}
bool cmp2(pair<string,piii> a, pair<string,piii> b){
    return a.s.f.s == b.s.f.s && a.s.f.f == b.s.f.f;
}
bool cmp3(pair<string,piii> a, pair<string,piii> b){
    return a.s.s.s == b.s.s.s && a.s.s.f == b.s.s.f;
}
bool cmp4(pair<string,piii> a, pair<string,piii> b){
    return a.s.s.s == b.s.f.s && a.s.s.f == b.s.f.f;
}
bool cmp5(pair<string,piii> a, pair<string,piii> b){
    return a.s.f.s == b.s.s.s && a.s.f.f == b.s.s.f;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    string s;
    int mx = -1;
    for(int i = 0,x; i < n; i++){
        cin>>s;
        int co = 0;
        bool op=1,ed=1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                co++;
            }
            else{
                co--;
            }
            if(0 > co){
                op = 0;
            }
        }
        co = 0;
        for(int i = s.length()-1; i >=0 ; i--){
            if(s[i] == ')'){
                co--;
            }
            else{
                co++;
            }
            if(0 < co){
                ed = 0;
            }
        }
        if(op){
            a[co].pb(s);
            mx = max(mx,co);
        }
        else if(ed){
            b[abs(co)].pb(s);
            mx = max(mx,co);
        }
    }

//    for(int i = 0; i < a[0].size(); i++){
//        for(int j = i+1; j < a[0].size(); j++){
//            c.pb({a[0][i] + a[0][j],{{0,i},{0,j}}});
//        }
//    }
    ans+=a[0].size()/2;
    for(int i = 1; i <= mx; i++){
        //cout<<a[i].size()<<" "<<b[i].size()<<endl;
//        for(int j = 0; j < a[i].size(); j++){
//            for(int k = 0; k < b[i].size(); k++){
//                c.pb({a[i][j] + b[i][k],{{i,j},{i,k}}});
//            }
//        }
        ans+=min(a[i].size(),b[i].size());
    }
//
//    c.erase(unique(c.begin(), c.end(), cmp),c.end());
//    c.erase(unique(c.begin(), c.end(), cmp2),c.end());
//    c.erase(unique(c.begin(), c.end(), cmp3),c.end());
//    c.erase(unique(c.begin(), c.end(), cmp4),c.end());
//    c.erase(unique(c.begin(), c.end(), cmp5),c.end());
//    for (pair<string,piii> i: c){
//        cout<<i.f<<" "<<i.s.s.s<<" "<<i.s.s.f<<endl;
//    }
    cout<<ans;

}
