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
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,m,ans,s,lv;
vector<piii> a;
stack<pii> l,r;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>s>>lv;
    for (int i =0,p,m,g; i < n; i++){
        cin>>p>>m>>g;
        a.pb({p,{m,g}});
    }
    sort(a.begin(),a.end());
    for(piii i : a){
        if(s > i.f){
            l.push(i.s);
        }else{
            break;
        }
    }
    reverse(a.begin(),a.end());
    for(piii i : a){
        if(s < i.f){
            r.push(i.s);
        }else{
            break;
        }
    }
    while(1){
        if(!l.empty() && lv >= l.top().f){
            lv+=l.top().s;
            l.pop();
        }
        else if(!r.empty() && lv >= r.top().f){
            lv+=r.top().s;
            r.pop();
        }
        else break;
    }
    cout<<lv;



}
