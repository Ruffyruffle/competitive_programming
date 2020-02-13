#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n,m,ans;

int part(int l, int r){
    int i = l-1;
    for (int j = l; j <= r-1; j++){
        if(j==r) continue;
        cout<<"C"<<" "<<j<<" "<<r<<endl; cout<<flush;
        int x;
        cin>>x;
        if (x==1){
            //abort();1

            i++;
            if(i!=j){cout<<"S "<<i<<" "<<j<<endl; cout<<flush; cin>>x;if(x==-1) abort();}
        }
    }
    if(i+1!=r){cout<<"S "<<i+1<<" "<<r<<endl; cout<<flush;
    int x; cin>>x; if(x==-1) abort();}
    //abort();
    return i+1;
}

void so(int l, int r){
    if (l<r){
        int p = part(l, r);
        so(l, p-1);
        so(p+1, r);
    }
}

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin>>n;
    //if(100 > n) return 1;
    so(1,n);
    cout<<"A"<<endl;
    return 0;



}
