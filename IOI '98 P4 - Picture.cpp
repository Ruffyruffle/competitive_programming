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
#define MAXN 20003
using namespace std;
int n,m,ans;
int t[MAXN];
int l[MAXN];
struct line{
    int x,y,y2,v;
}; vector<line> a;
bool cmp(line a, line b){return a.x<b.x;}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x,y,x2,y2; i < n; i++){
        cin>>x>>y>>x2>>y2;
        y2+=10001;
        y+=10001;
        a.pb({x+10001,y,y2,1});
        a.pb({x2+10001,y,y2,-1});
    }
    sort(a.begin(),a.end(),cmp);
    int last = 0;
    for(line i : a){
        if(last!=i.x){
            for(int j=1;j<MAXN;j++){
                if((t[j]==0) != (l[j]==0)) {ans++;}// cout<<last<<" "<<j<<endl;}
                if((t[j]==0) != (t[j-1]==0)) {ans+=i.x-last;}// cout<<i.x<<" "<<last<<endl;}
            }
            for(int j=1;j<MAXN;j++){
                l[j] = t[j];
            }
            last = i.x;
        }
        for(int j = i.y; j < i.y2; j++){
            t[j] += i.v;
        }
    }
    for(int j=1;j<MAXN;j++){
            if((t[j]==0) != (l[j]==0)) {ans++;}// cout<<last<<" "<<j<<endl;}
    }
    cout<<ans;



}
