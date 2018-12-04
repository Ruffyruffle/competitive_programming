#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 502
using namespace std;
int n,m;
vector<pair<pii, double>> a;
double b[MAXN];

int main(){
    MEM(b, INF);
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    string s,ss;
    unordered_map<string, int> d;
    for (int i =0; i < n; i++){
        cin>>s; d[s] = i;
    }
    double x;
    for(int i = 0; i < m; i++){
        cin>>s>>ss>>x;
        a.pb({{d[s],d[ss]}, x});
    }

    b[d["APPLES"]] = 1;
    for(int j = 0; j < n-1; j++){
        for(pair<pii, double> i : a){
            b[i.first.second] = max(b[i.first.first] * i.second, b[i.first.second]);
        }
    }

    double an = b[d["APPLES"]];

        for(pair<pii, double> i : a){
            b[i.first.second] = max(b[i.first.first] * i.second, b[i.first.second]);
        }


    if(b[d["APPLES"]]-an > 0.1){
        cout<<"YA";
    }else{
    cout<<"NAW";}

}
