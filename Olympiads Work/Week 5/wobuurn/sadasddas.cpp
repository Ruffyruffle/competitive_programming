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
#define MAXN 1000000
using namespace std;
int n;
vector<string> a;
void solve(string p, int l){
    if(l == 0){
        a.pb(p);
        return;
    }

    for(int i = 1; i <= 26; i++){
        char c = char(i+96);
        string s = p + c;
        solve(s,l-1);
    }
}



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= 3;i++ ){
        solve("", i);
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<< " ";
    }





}
