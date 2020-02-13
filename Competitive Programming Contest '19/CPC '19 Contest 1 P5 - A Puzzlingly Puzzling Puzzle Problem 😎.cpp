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
int n,m,ans,k,q;
string s[2];
string g;
unordered_map<string, int> a[2];
void solve(string pos, int cur, int player){
    if(a[player][pos] && cur >= a[player][pos]) return;
    if(cur > 15) return;
    a[player][pos] = cur;
    if(pos[0] == 0){
        string ss = pos;
        ss[0] = ss[1];
        ss[1] = 0;
        solve(ss, cur+1, player);
        string ss = pos;
        ss[0] = ss[2];
        ss[2] = 0;solve(ss, cur+1, player);
    }if(pos[1] == 0){
        string ss = pos;
        ss[1] = ss[0];
        ss[0] = 0;solve(ss, cur+1, player);
        string ss = pos;
        ss[3] = ss[1];
        ss[1] = 0;solve(ss, cur+1, player);
    }if(pos[2] == 0){
        string ss = pos;
        ss[2] = ss[0];
        ss[0] = 0;solve(ss, cur+1, player);
        string ss = pos;
        ss[2] = ss[4];
        ss[4] = 0;solve(ss, cur+1, player);
    }if(pos[3] == 0){
        string ss = pos;
        ss[3] = ss[1];
        ss[1] = 0;solve(ss, cur+1, player);
        string ss = pos;
        ss[3] = ss[2];
        ss[2] = 0;solve(ss, cur+1, player);
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    string x;
    for (int i =0; i < k; i++){
        for(int j = 0; j < 2; j++){
            for(int l = 0; l < 2; l++){
                cin>>x; s[i] += x;
            }
        }
        solve(s[i]);
    }

    for (int i =0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin>>x; g+=x;
        }
    }
    if(a[0][g] <= a[1][g]){
        cout<<1<<" "<<a[0][g];
    }
    else cout<<2<< " " << a[1][g];



}
