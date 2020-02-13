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
#define MAXN 200001
using namespace std;
int n,m,ans;
//int a[MAXN];
int b,c;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>b>>c;
    int cm = c;
    //cout<<cm<<endl;
    for (int i =0,x; i < n; i++){
        cin>>x;
        if(x==1){
            if(c == cm){
                c--;
            }
            else if(b){
                b--; c=min(cm, c+1);
            }
            else if(c)c--;
            else{
                cout<<i; return 0;
            }

        }
        else{
            if(c) c--;
            else if(b) b--;
            else{
                cout<<i; return 0;
            }

        }
        //cout<<b<<" "<<c<<endl;
    }
    cout<<n;



}
