#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
vector<pair<int,int> > l;
set<int> tim;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second > b.second);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c = 0;
    cin>>n;
    for (int i =0; i < n; i++){
        cin>>a>>b;
        l.pb(make_pair(-a,b));
        if(a>c)
            c=a;
    }

    for(int i = 0; i < c; i++){
        tim.insert(-i);
    }
    sort(l.begin(), l.end(), cmp);

    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = tim.upper_bound(l[i].first);
        if(it != tim.end()){
            tim.erase(it);
            ans+=l[i].second;
        }
    }
    cout<<ans;
}

