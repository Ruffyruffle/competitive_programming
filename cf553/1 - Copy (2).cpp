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
#define MAXN 501
using namespace std;
int n,m;
string ans = "";
int a[MAXN][MAXN];
unordered_map<string, bool> memo;
void solve(int flag, int row, string path){
    if(ans!="") return;
    if(row == n){
        if(flag!=0) ans = path;
        return;
    }
    if(memo[to_string(row)+'.'+to_string(flag)]) return;
    memo[to_string(row)+'.'+to_string(flag)]=1;
    //cout<<'a'<<endl;
    for(int i = 0; i < m; i++){
        solve(flag^a[row][i], row+1, path+to_string(i+1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    solve(0,0,"");
    if(ans == "") cout<<"NIE";
    else{
        cout<<"TAK"<<endl;
        for(char &i : ans){
            cout<<i<<" ";
        }
    }



}
