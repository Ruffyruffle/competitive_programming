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
#define MAXN 46657
using namespace std;
int n,m,ans;
vector<string> a;
bool temp[6];
bool no[MAXN];
void pre(string cur, int sz){
    if(sz == 6){
        a.pb(cur); return;
    }
    for(int i = 1; i<= 6; i++){
        pre(cur + to_string(i),sz+1);
    }
}
//co,ex
inline pii check(string &s, string &test){
    int c=0,e=0;
    for(int i=0;i<6;i++){
        if(s[i]==test[i])e++;
        else if(temp[s[i]-'1'])c++;
    }
    return {c,e};
}
void purge(string s, int &c, int &e){
    for(int i = 0; i < a.size(); i++){
        if(no[i])continue;
        MEM(temp,0);
        for(char &j : a[i]){
            temp[j-'1']=1;
        }
        pii res = check(a[i], s);
        if(!(res.f==c && res.s==e))no[i]=1;
    }
}
string next(){
    int ms=0; string best;
    for(int i = 0; i < a.size(); i++){
        //cout<<i<<endl;
        if(no[i])continue;
        MEM(temp,0);
        for(char &i : a[i]){
            temp[i-'1']=1;
        }
        int score = INF;

        for(int j=0;j<=6;j++){
            for(int k=0; k+j <= 6; k++){
                int cur = 0;
                //for(string &test : a){
                for(int z = 0; z < a.size(); z++){
                    if(no[z]) continue;
                    pii t2 = check(a[i],a[z]);
                    if(t2.f!=j||t2.s!=k) cur++;
                }
                score = min(score,cur);
            }
        }
        if(score > ms){
            ms=score; best = a[i];
        }
    }
    return best;
}
void solve(){
    int co=0,e,c;
    cout<<"111222"<<endl;
    cin>>c>>e;
    purge("111222",c,e);
    for(int i = 0; i < 4; i++){
        string t = next();
        cout<<t<<endl;
        cin>>c>>e;
        purge(t,c,e);
    }
    for(int i =0; i < a.size(); i++){
        if(!no[i]) cout<<a[i]; break;
    }
}

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    pre("",0);
    solve();
}
