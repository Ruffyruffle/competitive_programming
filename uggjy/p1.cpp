#include <bits/stdc++.h>
using namespace std;
vector<int> x;
vector<int> y;
int main(){
    int n, a ,b;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout<<2*abs(*--x.end() - *x.begin()) + 2*abs(*--y.end() - *y.begin());
}
