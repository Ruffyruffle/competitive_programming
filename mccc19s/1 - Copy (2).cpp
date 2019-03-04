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
#define MAXN 21
using namespace std;
int n,m,ans;
char a[MAXN][MAXN];
int ans2=0;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0; i < n; i++){
        string s;cin>>s;
        //cout<<s<<endl;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
            //cout<<a[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i =0;i < n; i++){
        bool ws=1,wj=1,ws2=1,wj2=1;
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'O'){
                wj=0;
            }
            else {
                ws=0;
            }
            if(a[j][i] == 'O'){
                wj2=0;
            }
            else{
                ws2=0;
            }
        }
        if(wj) {ans++; }//cout<<i<<endl;}
        if(wj2) ans++;
        if(ws) ans2++;
        if(ws2) ans2++;
    }
        bool ws=1,wj=1,ws2=1,wj2=1;
    for(int i =0;i < n; i++){

        if(a[i][i] == 'O'){
            wj=0;
        }
        else {
            ws=0;
        }
        if(a[i][n-i] == 'O'){
            wj2=0;
        }
        else{
            ws2=0;
        }

    }
        if(wj) {ans++; }//cout<<i<<endl;}
        if(wj2) ans++;
        if(ws) ans2++;
        if(ws2) ans2++;
    cout<<ans<<" "<<ans2<<endl;
    if(ans==ans2){
        cout<<"Tie";return 0;
    }
    cout<<(ans>ans2?"Joon":"Shon");



}
