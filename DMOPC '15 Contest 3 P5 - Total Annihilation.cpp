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
#define MAXN 38
using namespace std;
ll n,m,ans;
int a[MAXN]; //vector<int> a1,a2;
unordered_map<ll,int> s;//s2;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =0; i < n; i++){
        cin>>a[i];
    }
    for(int i = n ; i < n+m; i++){
        cin>>a[i]; a[i] = -a[i];
    }
    int h = (n+m)>>1;
    vector<int> a1(a,a+h), a2(a+h,a+n+m);
//    for(int i = 1; i <= n+m; i++){
//        if(i <= (n+m)/2){
//            a1.pb(a[i]);
//        }
//        else a2.pb(a[i]);
//    }
    for(int i= 0; i < 1<<a1.size(); i++){
        ll sum = 0;
        //cout<<i<<endl;
        for(int j = 0; j < a1.size(); j++){
            //cout<<i<<" "<<j<<" "<<(i&(1<<j))<<endl;
            if(i & (1<<j)) sum+=a1[j];
        }
        if(s[sum]) s[sum]++;
        else s[sum] = 1;
    }
    for(int i= 0; i < 1<<a2.size(); i++){
        ll sum = 0;
        for(int j = 0; j < a2.size(); j++){
            //cout<<i<<" "<<j<<" "<<(i&(1<<j))<<endl;
            if(i & (1<<j)) sum+=a2[j];
        }
//        if(s2[sum]) s2[sum]++;
//        else s2[sum] = 1;
        ans+=s[-sum];
    }

    cout<<ans-1;






}
