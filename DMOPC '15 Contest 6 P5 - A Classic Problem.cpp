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
#define MAXN 3000000
using namespace std;
int n,k; ll ans;
int a[MAXN]; multiset<int> s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i =0,x; i < n; i++){
        cin>>a[i];
    }
    int l =0;//ans2=0;
    for(int i = 0; i < n; i++){
        s.insert(a[i]);
        while(*--s.end()-*s.begin() > k){
            s.erase(s.find(a[l++]));
        }
        //cout<<s.size()<<" "<<i-l+1<<endl;
        ans+=i-l+1;
        //ans2+=s.size();
        //for(int i : s) cout<<i<<" ";
        //cout<<endl;
    }
    cout<<ans;//<<" "<<ans2;
}
