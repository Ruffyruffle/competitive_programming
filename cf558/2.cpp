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
#define MAXN 100005
using namespace std;
int n,m,ans;
vector<int> a;
int c[MAXN],c2[MAXN];;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        cin>>x;
        a.pb(x);
        c[x]++;
    }
    int cur =0, cur2=INF;
    for(int i = 0; i < MAXN; i++){
        if(c[i] == 0) continue;
        if(c2[c[i]]==0) cur++;
        c2[c[i]]++;
        //cout<<c[i]<<endl;
        if(c2[c[i]] != 0)cur2 = c[i];
    }
    //cout<<cur2;
    if((cur == 2 && (c2[cur2+1]==1 || (c2[cur2] == 1&&c2[cur2-1]))) ||(cur == 1 && c2[cur2] == 1) ||(cur == 2 && c2[1]==1)||(cur == 1 && c2[1])){
        cout<<n;return 0;
    }
    for(int i = n-1; i >= 0; i--){
        c2[c[a[i]]]--;
        if(c2[c[a[i]]]==0) cur--;
        c[a[i]]--;
        if(c[a[i]]!=0 && c2[c[a[i]]]==0) cur++;
        c2[c[a[i]]]++;
        //cout<<c[a[i]]<<endl;
        if(c2[c[a[i]]] != 0)cur2 = c[a[i]];
        //cout<<c[a[i]]<<endl;
        //cout<<cur2<<endl;
        //cout<<c2[cur2+1]<<endl;
        if((cur == 2 && (c2[cur2+1]==1 || (c2[cur2] == 1&&c2[cur2-1]))) ||(cur == 1 && c2[cur2] == 1) ||(cur == 2 && c2[1]==1)||(cur == 1 && c2[1])){
            cout<<i;return 0;
        }
    }


}
