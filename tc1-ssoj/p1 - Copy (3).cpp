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
int n,m,ans;
char o[] = {'(','[','{'}, cl[] = {')',']','}'};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);string s;
    cin>>n;
    for (int i =0; i < n; i++){
        cin>>s; stack<char> a; bool ans = 1;
        for(char c : s){
            for(int j=0;j<3;j++){
                if(c==o[j]) a.push(o[j]);
                if(c==cl[j]){
                    if(a.empty()||a.top() != o[j]) ans=0;
                    if(!a.empty()) a.pop();
                }
            }
        }
        if(!a.empty()) ans = 0;
        cout<<(ans?"yes":"no")<<endl;
    }



}
