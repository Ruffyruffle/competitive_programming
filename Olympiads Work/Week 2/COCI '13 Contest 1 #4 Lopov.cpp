#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include<set>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 300001
using namespace std;
int n,k;
pair<int,int> dia[MAXN];

bool srt(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
int main(){
    multiset<int>bag;
    cin>>n>>k;
    for (int i =0; i < n; i++){
        cin>>dia[i].first>>dia[i].second;
    }
    int b;
    for(int i = 0; i < k; i++){
        cin>>b;
        bag.insert(b);
    }
    //cout<<"a";
    ll ans = 0;
    sort(dia, dia+n, srt);
    for(int i = 0 ; i < n; i++){
        if(bag.lower_bound(dia[i].first) != bag.end()){
            ans += dia[i].second;
            bag.erase(bag.lower_bound(dia[i].first));
        }
    }
    cout<<ans;
}
