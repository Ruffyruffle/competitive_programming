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
#define MAXN 100001
using namespace std;
int n,m;
ll a[MAXN], sm[MAXN];

void add(ll *bit, int val, int i){
    while(i < MAXN+1){
        bit[i] += val;
        i+=(-i&i);
    }
}
//
//void upR(int *BIT, int *BIT2, int n, int val, int l, int r)
//{
//    add(BIT,n,l,val);
//    add(BIT,n,r+1,-val);
//    add(BIT2,n,l,val*(l-1));
//    add(BIT2,n,r+1,-val*r);
//}

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
    cin>>n;
    for (int i =1; i < n+1; i++){
        cin>>a[i];
        add(sm, a[i], i);
    }
    int b;
    int x,y;
    ll d;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>b;
        if (b==1){
            cin>>x>>y;
            cout<<sum(sm, y) - sum(sm, x-1)<<endl;
        }
        else if (b ==2){
            cin>>x>>y;
            for(int i = x; i <= y; i++){
                if(a[i] != 1){
                    int d = floor(sqrt(a[i]));
                    int diff =  d - a[i];
                    add(sm, diff, i);
                    a[i] = d;
                }
            }
        }
    }
}
