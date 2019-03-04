#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define s second
#define f first
#define pb push_back
int n, cur, ans;
vector<pii> a;

bool cmp(pii a, pii b){return a.f > b.f;}
auto cmp2 = [](pii a, pii b){return a.s > b.s;};
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0,x,y; i < n; i++){
        cin>>x>>y;
        if(cur >= x || y == 0) cur++;
        else a.pb({x,y});
    }
    sort(a.begin(),a.end(),cmp);
    priority_queue<pii, vector<pii>, decltype(cmp2)> b(cmp2);

    for(int j = 0; j < a.size(); j++){
        pii& i = a[j];
        if(cur >= i.f){
            cur++;
        }
        else if(b.size()+a.size()-j > i.f - cur)
            b.push(i);
        else {cur++; ans+=i.s;}
    }
    while(!b.empty()){
        if(cur >= b.top().f){
            b.pop();
            cur++;
        }
        else{
            //cout<<b.top().s<<endl;
            ans+=b.top().s;
            cur++;
            b.pop();
        }
    }
    cout<<ans;

}
