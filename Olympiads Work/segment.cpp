#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000001
using namespace std;
int n,k;
vector<pair<int, int> > line;
bool l[MAXN];

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
    cin>>n;
    int a,b;
    for(int i = 0; i < n; i++){

        cin>>a>>b;
        line.pb(make_pair(a,b));
    }
    sort(line.begin(), line.end(), cmp);

    int ans = 0;
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (line[i].first >= cur) {
            ans+=line[i].second;
            cur = line[i].second;
        }
    }
    cout<<ans;
}
