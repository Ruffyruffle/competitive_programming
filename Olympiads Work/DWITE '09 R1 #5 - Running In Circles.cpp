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
#define MAXN 101
using namespace std;
int n;

void solve(){
    vector<int> a[MAXN];
    cin>>n;
    int x,y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        a[x].pb(y);
    }

    queue<int> f;
    f.push(0);
    int cur = 0;
    while(!f.empty()){
        cur = f.front();
        for(int i = 0; i < a[cur].size(); i++){

        }
    }



}

int main(){
    for (int i =0; i < 5; i++){
        solve();


    }





}
