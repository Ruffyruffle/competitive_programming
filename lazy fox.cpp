#include<bits/stdc++.h>
using namespace std;
struct line{
    int st,en,dis;
    line(int a, int b, int adis){
        st = a; en = b; dis = adis;
    }
};
void dis(pair<int,int> a, pair<int,int> b){
    return(pow(b.first - a.first,2) + pow(b.second - a.second, 2));
}

int main(){
    vector<line> li;
    vector<pair<int,int> > po;
    int n,a,b;
    for(int i = 0; i<n; i++){
        cin>>a>>b; po.push_back({a,b});
    }
    po.push_back({a,b});
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if (i!=j)
                li.push_back(i,j,dis(po[i], po[j]));
        }
    }
}
