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


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(1){
        if(ans%2==0){
            if(n>=2 && m>=2){
                n-=2;m-=2;
            }
            else if(n>=1&&m>=12){
                n--;m-=12;
            }
            else if(m>=22){
                m-=22;
            }
            else break;
        }
        else{
            if(m>=22){
                m-=22;
            }
            else if(n>=1&&m>=12){
                n--;m-=12;
            }
            else if(n>=2 && m>=2){
                n-=2;m-=2;
            }
            else break;
        }
        ans++;
    }
    cout<<(ans%2==0?"Hanako":"Ciel");



}
