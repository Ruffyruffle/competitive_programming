#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
vector<pair<long double,long double>> a;
//unordered_map<ll, int> xx,yy;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll ans =0;
    int n;
    cin>>n; ll x,y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        a.push_back({x,y});
//        if(xx[x]) xx[x]++;
//        else xx[x] = 1;
//        if(yy[y]) yy[y]++;
//        else yy[y] = 1;
    }
//    for(int i = 0; i < n; i++){
//        for(int j = i+1; j < n; j++){
//            if(a[i].f != a[j].f && a[i].s != a[j].s){
//                ans+= n-j-1;
//            }
//            else if(a[i].f == a[j].f){
//                ans+=n-xx[a[i].f]-1;
//            }
//            else if(a[i].s == a[j].s){
//                ans+=n-yy[a[i].s]-1;
//            }
//        }
//    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(((a[j].f - a[i].f) == 0 ) == ((a[k].f - a[i].f)==0) && ((a[k].f - a[i].f)==0) ) continue;
                if((a[j].f - a[i].f) == 0 ||(a[k].f - a[i].f)==0) {ans++; continue;}
                if((a[j].s - a[i].s)/ (a[j].f - a[i].f) != (a[k].s - a[i].s)/(a[k].f - a[i].f)){
                    ans++;
                    //cout<<a[i].f<<" "<<a[i].s<<" "<<a[j].f<<" "<<a[j].s<<" "<<a[k].f<<" "<<a[k].s<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;

}
