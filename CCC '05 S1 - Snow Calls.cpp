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
#define Suf(a,b) (a.size() <= b.size() && equal(a.rbegin(), a.rend(), b.rbegin()))
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
unordered_map<char,int> a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(char i = 0 ; i <= 'R'-'A'; i++){
        a[i+'A'] = i/3 + 2;
    }
    a['S'] = 7;
    for(char i = 0 ; i <= 'Y'-'T'; i++){
        a[i+'T'] = i/3 + 8;
    } a['Z'] = 9;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        string ss = ""; int j = 0;
        for(char c : s){
            if(c=='-'||j>9) continue;
            if(j == 3 || j == 6) ss+='-';
            j++;
            if(a[c]){
                ss+=to_string(a[c]);
            }else ss+=c;
        }
        cout<<ss<<endl;
    }


}
