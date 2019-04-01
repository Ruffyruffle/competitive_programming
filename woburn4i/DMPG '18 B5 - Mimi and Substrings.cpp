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
int n,m,ans,k;
unordered_map<char,int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s>>k;
    int r =0,d=0;
    while(r < k-1){
        if(a[s[r]] == 0) d++;
        a[s[r++]]++;
    }
    for(int i = 0; i <= s.length()-k; i++){
        if(a[s[r]] == 0) d++;
        a[s[r++]]++;
        if(d==1)ans++;
        a[s[i]]--;
        if(a[s[i]] == 0) d--;
    }
    cout<<ans;



}
