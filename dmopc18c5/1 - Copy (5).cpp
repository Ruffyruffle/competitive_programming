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
#define MAXN (1<<20) + 1
using namespace std;
int n,m,ans;
//bool a[MAXN],b[MAXN];
bool vis[MAXN];

void solve(ll flag, int next){
    if(next!= -1){
        flag^=(1<<next);
        flag^=(1<<next+1);
    }
    //cout<<flag<<endl;
    if(vis[flag]) return;
    vis[flag] = 1;
    for(int i = 0; i < n-1; i++){
        if((flag&(1<<i) == 0) == (flag&(1<<i+1) == 0)){
            solve(flag, i);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n; string s,s2;
    cin>>s;
    ll flaga=0, flagb=0; int cf =0 ,cf2 =0; bool d=0;
    for (int i =0; i < n; i++){
        if(s[i] == 'F'){
            cf++;
        }
//        if(s[i]=='F'){
//            flaga|= (1<<i);
//        }
    }
    for (int i =0; i < n-1; i++){
        if(s[i] == s[i-1]){
            d=1;
        }
    }
    cin>>s2;
    for(int i = 0; i < n; i++){
        if(s2[i] == 'F'){
            cf2++;
        }
//        if(s[i]=='F'){
//            flagb|= (1<<i);
//        }
    }
//    int l = 0, r = n-2;
//    while(r+1>=l){
//        if(a[l] == b[l]){
//            l++;
//        }
//        else if(a[r+1] == b[r+1]){
//            r--;
//        }
//        else if(a[l+1] == a[l] && l < n-1){
//            a[l] = !a[l7];
//            a[l+1] = !a[l+1];
//            l++;
//        }
//        else if(a[r+1] == a[r] && r>=0){
//            a[r] = !a[r];
//            a[r+1] = !a[r+1];
//            r--;
//        }
//        else{
//            break;
//        }
//    }
//    bool c= 1;
//    for(int i = 0; i < n; i++){
//            //cout<<a[i]<<" "; //break;
//        if(a[i] != b[i]){
//            c=0;
//        }
//    }
//    solve(flaga, -1);
//    cout<<(vis[flagb]?"YES":"NO");
    if((cf%2==0 != cf2%2==0) || !d){
        cout<<"NO";
    }
    else cout<<"YES";


}
