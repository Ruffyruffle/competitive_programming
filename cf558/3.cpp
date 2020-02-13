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
vector<int> a;
int c[11];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0,x; i < n; i++){
        cin>>x;
        a.pb(x);
        c[x]++;
    }
    int cur = 0; bool ex=0; bool pos=1;
    for(int i = 1; i <= 10; i++){
        if(c[i]==0) continue;
        if(cur){
                if(c[i] != cur && (c[i]-cur==1 || c[i]==1)){
                    if(!ex)ex=1;
                    else pos=0;
                }
                else if(c[i] != cur){
                    pos=0;
                }
            }
            if(!cur){
                cur = c[i];
            }
    }
    if((pos&&ex)||(pos&&cur==1)){
        cout<<n; return 0;
    }
    cur = 0; ex = 0; pos = 1;
    for(int i = 10; i >=0; i--){
        if(c[i]==0) continue;
        if(cur){
                if(c[i] != cur && (c[i]-cur==1 || c[i]==1)){
                    if(!ex)ex=1;
                    else pos=0;
                }
                else if(c[i] != cur){
                    pos=0;
                }
            }
            if(!cur){
                cur = c[i];
            }
    }
    if((pos&&ex)||(pos&&cur==1)){
        cout<<n; return 0;
    }

    for(int j = n-1; j >=0; j--){
        cur = 0; ex = 0; pos = 1;
        c[a[j]]--;
        //cout<<c[a[i]]<<endl;
        for(int i = 1; i <= 10; i++){
            if(c[i]==0) continue;
            //cout<<j<<" "<<pos<<endl;
            if(cur){
                if(c[i] != cur && (c[i]-cur==1 || c[i]==1)){
                    if(!ex)ex=1;
                    else pos=0;
                }
                else if(c[i] != cur){
                    pos=0;
                }
            }
            if(!cur){
                cur = c[i];
            }
        }
        if((pos&&ex) ||(pos&&cur==1)){
            cout<<j; return 0;
        }
        cur = 0; ex = 0; pos = 1;
        for(int i = 10; i >= 1; i--){
            if(c[i]==0) continue;
            //cout<<j<<" "<<pos<<endl;
            if(cur){
                if(c[i] != cur && (c[i]-cur==1 || c[i]==1)){
                    if(!ex)ex=1;
                    else pos=0;
                }
                else if(c[i] != cur){
                    pos=0;
                }
            }
            if(!cur){
                cur = c[i];
            }
        }
        if((pos&&ex) ||(pos&&cur==1)){
            cout<<j; return 0;
        }
    }



}
