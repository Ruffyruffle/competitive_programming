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
#define MAXN 1001
using namespace std;
int n,m,ans;
int co[26];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    string s;
    for (int i =0; i < n; i++){
        cin>>s;
        MEM(co, 0);
        int let = 0;
        for(char c : s){
            co[c-97]++;
            if(co[c-97] == 1)
                let++;
        }
        if(let == 1 || (let == 2 && s.length() == 2)){
            cout<<-1<<endl;
        }
        else{
            vector<pair<int,char>> cc;
            for(int j = 0 ; j < 26; j++){
                if(co[j] >0 )
                    cc.pb({co[j],char(j+97)});
            }
            sort(cc.begin(), cc.end());
            for(pair<int,char> k : cc){
                cout<<string(k.f, k.s);
            }
            cout<<endl;
        }
    }




}
