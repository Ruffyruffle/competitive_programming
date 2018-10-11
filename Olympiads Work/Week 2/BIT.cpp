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
int n,m;
ll a[MAXN], rk[MAXN], sm[MAXN];

void add(ll *bit, int val, int i){
    while(i < MAXN+1){
        bit[i] += val;
        i+=(-i&i);
    }
}

ll sum (ll *bit, int i){
    ll ans = 0;

    while (i>0){
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i =1; i < n+1; i++){
        cin>>a[i];
        add(sm, a[i], i);
        add(rk, 1, a[i]);
    }
    char b;
    int x,y;
    ll d;
    for(int i = 0; i < m; i++){
        cin>>b;
        if(b=='Q'){
            cin>>x;
            cout<<sum(rk,x)<<endl;
        }
        else
            cin>>x>>y;
            if (b=='S'){
                cout<<sum(sm, y) - sum(sm, x-1)<<endl;
            }
            else if (b =='C'){
                int diff = y-a[x];
                add(sm, diff, x);
                add(rk, 1, y);
                add(rk, -1, a[x]);
                a[x] = y;
            }
    }
}
