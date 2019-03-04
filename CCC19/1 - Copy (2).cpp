#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000002
#define s second
#define f first
#define pb push_back
#define endl '\n'
typedef pair<int,int> pii;
int n,m,k,ans,t;
bool p[MAXN];
vector<int> a;

void sieve(int n){
    for(int i=2;i*i<=n;i++){
        if(!p[i]){
            for(int j=i*i; j<=n; j+=i){
                p[j]=1;
                //cout<<j<<endl;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(!p[i]){
            //cout<<i<<endl;
            a.pb(-i);
        }
    }
}

void solve(){
    cin>>n;
    n=-n;
    int ans = 0, ans2 =0;

    for(vector<int>::iterator i = lower_bound(a.begin(),a.end(), n); i != a.end(); ++i){
        //cout<<*i<<" "<<(-2*n)-(-*i)<<endl;
        if(!p[(-2*n)-(-*i)]){
            cout<<(-*i)<<" "<<(-2*n)-(-*i)<<endl;
            return;
        }
        //cout<<2*n-*i<<endl;
    }
    //cout<<n<<"a"<<endl;

}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    sieve(MAXN-1);
//    for(int i : a){
//        cout<<i<<endl;
//    }
    //cout<<a.size();
    reverse(a.begin(),a.end());
    for(int i = 0; i < t; i++){solve();}
    //cout<<p[9];
    return 0;

}
