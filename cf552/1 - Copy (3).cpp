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
int n,m,ans;
int a,b,c;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>a>>b>>c;
    int aa = 3;
    int bb = 2;
    int cc = 2;
    int week = min(min(a/aa, b/bb), c/cc);
    a-=week*aa; b-=week*bb; c-=week*cc;

    for(int i = 1; i <= 7; i++){
        int a2 = a,b2=b,c2=c;
        for(int j = i; j <= i+7; j++){
            if((j>7?j-7:j) == 1 || (j>7?j-7:j) == 4 || (j>7?j-7:j) == 7){
                if(a2) a2--;
                else {ans = max(j-i,ans);break;};
            }
            if((j>7?j-7:j) == 2 ||(j>7?j-7:j) == 6){
                if(b2) b2--;
                else {ans = max(j-i,ans);break;};
            }
            if((j>7?j-7:j) == 3 || (j>7?j-7:j) == 5){
                if(c2) c2--;
                else {ans = max(j-i,ans);break;};
            }
        }
        //cout<<i<<" "<<ans<<endl;

    }
    cout<<week*7 + ans;




}
