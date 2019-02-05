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
#define MAXN 100001
using namespace std;
int n,m;
int ans[4];
vector<pii> a;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    string ss[4] = {"Deluxe Tuna Bitz", "Bonito Bitz","Sashimi","Ritzy Bitz"};
    reverse(ss,ss+4);
    unordered_map<string,int> mpi;
    int c = 0;
    string s;
    for (int i =0; i <= n; i++){
        getline(cin,s);
        for(int j = 0; j < 4; j++){
            if(s==ss[j])
                ans[j]++;
        }
    }
    for(int i = 0; i <4; i++){
        a.pb({ans[i], i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(pii i : a){
        if(i.f==0) continue;
        cout<<ss[i.s]<<" "<<i.f<<endl;
    }


}
