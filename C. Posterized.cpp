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
#define MAXN 100002
using namespace std;
int n,m,ans;
int a[MAXN], key[256];
vector<int> b;
int main(){
    MEM(key, -1);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0; i < n; i++){
        cin>>a[i]; b.pb(a[i]);
    }
    UNI(b);

    for(int i : b){
        vector<int> c;
        if(key[i] == -1){
            for(int j = i; j >= 0 && j > i-m; j--){
                if(key[j] == -1){
                    key[i] = j;
                    c.pb(j);
                }
                else{
                    if(key[j] > i-m){
                        key[i] = key[j];
                    }
                }
            }
            for(int j : c){
                key[j] = key[i];
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        cout<<key[a[i]]<<" ";
    }



}
