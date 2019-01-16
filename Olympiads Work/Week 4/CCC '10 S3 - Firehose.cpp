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
int n,m,ans=INF;
vector<int> a;

bool solve(int cur){
    int last = -1,t=0;
    for(int i : a){
        if(last<i){
            t++;
            last = i+(cur*2);
        }
    }
    int d = 0;
    while(a[d] < a[0] + 2*cur && d < n){
        d++;
    }
    int ex = a[0] + 2*cur - a[d-1];
    //cout<<1000000-(a[0]-ex)<<endl;
//    if(last - 1000000 >= a[d-1])
//        t--;
    if(ex>0){
        //cout<<a[0]-ex<<endl;
        if(1000000 + (a[0] - ex) <= last - 2*cur)
            t--;
    }

    return m>=t;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        cin>>x; a.pb(x);
    }
    cin>>m;
    sort(a.begin(),a.end());
    int l=0,r=1e6,mid;
    while(r>=l){
        mid = (l+r)/2;
        if(solve(mid)){
            ans = mid;
            //cout<<mid<<endl;
            r = mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;



}
