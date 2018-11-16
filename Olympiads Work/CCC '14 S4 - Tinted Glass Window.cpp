#include <bits/stdc++.h>
using namespace std;

vector<int> xa,xb,ya,yb,tint;
vector<int> x,y;
unordered_map<int, int> xRank;
unordered_map<int, int> yRank;

int dif[1001][1001];

int main(){
    int n, t;
    cin>>n>>t;

    for(int i = 0; i < n; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        xa.push_back(a);
        xb.push_back(b); x.push_back(a); x.push_back(b);
        ya.push_back(c);
        yb.push_back(d); y.push_back(c); y.push_back(d);
        tint.push_back(e);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i = 0; i < n*2; i++){
        xRank[x[i]] = i;
        yRank[x[i]] = i;
    }

    for(int i  = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dif[xrank[xa[i]]][yrank[ya[i]]] += tint[i];
            dif[xrank[xb[i]]][yrank[yb[i]]] += tint[i];

        }
    }






}
