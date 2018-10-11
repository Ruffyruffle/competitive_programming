#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 2001
using namespace std;
int n;
vector<pair<double, int>> a[MAXN];
pair<int,int> house[MAXN], b = mp( 0, 0);

bool srt(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first < b.first);
}

double dist(pair<int,int> a, pair<int,int> b){
    return -(sqrt(pow(a.second - b.second,2 ) + pow(a.first - b.first,2)));
}

int main(){

    cin>>n;
    for (int i =0; i < n; i++){
        cin>>house[i].first;
        cin>>house[i].second;
    }
    vector<pair<double, int>> first;
    for(int j = 0; j < n; j++){
        first.pb(mp(dist(b, house[j]), j));
    }
    sort(first.begin(), first.end());

    for (int i =0; i < n; i++){
        pair<int,int> root = house[i];
        for(int j = 0; j < n; j++){
            if (i!=j){
                a[i].pb(mp(dist(root, house[j]), j));
            }
        }
        sort(a[i].begin(), a[i].end(), srt);
    }
    ll ans = 1;
    int last;
    double lastdis;
    pair<double, int> c = *--first.end();
    last = c.second;
    lastdis = c.first;

    while(1){
        if (a[last].lower_bound(a[last].begin(), a[last].end(), mp(lastdis, -INF), srt) == a[last].end())
            break;
        else{
           pair<double, int> t = *a[last].lower_bound({lastdis, -INF});
           ans++;
           lastdis = t.first;
           last = t.second;
        }
    }






}
