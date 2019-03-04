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

double screen(double  r, double  r2){
return 1-(1-r)*(1-r2);}

double a(double r, double r2){
    if(r<0.5){
        return 2*r*r2;
    }
    else return 1- (2*(1-r)*(1-r2));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string n;
    cin>>n;
    double r,g,b,r2,b2,g2;
    cin>>r>>g>>b>>r2>>g2>>b2;
    cout<<fixed<<setprecision(7);
    if(n=="Multiply"){
        cout<<r*r2<<" "<<g*g2<<" "<<b*b2<<endl;
    }
    else if(n=="Screen"){
        cout<<screen(r,r2)<<" "<<screen(g,g2)<<" "<<screen(b,b2)<<endl;
    }
    else if(n=="Overlay"){
        cout<<a(r,r2)<<" "<<a(g,g2)<<" "<<a(b,b2)<<endl;
    }



}
