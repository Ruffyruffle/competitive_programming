#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
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
int p= 0; bool prav;
const int y = 50001;

int tuda(string s){
    int k = 0;
    bool f = 0;
    prav = 1;
    bool r = 1;
    for(char c : s){
        if(c=='('){
            k++;
           }
           else{
            k--;

           }

        if(k<0){
            f = 1; r = 0;
        }
        if((k>=0) && f){
            prav = 0;

        }
    }
    if(k!=0){
        r = 0;
    }
    if(r){
        p++;
    }
    return k;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    string s,t;
    int vn[y] = {0};
    int vk[y] = {0};
    int gg;
    for (int i =0; i < n; i++){
        cin>>s;
        gg = tuda(s);
        if((prav) && gg >=0)
            vn[gg]++;
        t = s;
        for(int j = 0; j < s.length(); j++){
                t[j] = (s[s.length() -1 -j] == '(')?')':'(';
        }
        gg = tuda(t);
        if((prav) && gg >=0)
            vk[gg]++;

    }
    int res = (p/2)/2;
    for(int i = 1; i < y; i++){
        res+=min(vn[i],vk[i]);
    }
    cout<<res;



}
