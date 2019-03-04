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
#define MAXN 1002
using namespace std;
int n,m,ans;
double a[MAXN][MAXN];

int check(double mid){ //0 = under, 1 = on, 2 = over
    double s = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double t = a[i][j] * mid;
            if(t > 1.0){
                t = 1.0;
            }
            //cout<<t<<endl;
            s+=t;
        }
    }
    s/=(n*m);
    //cout<<mid<<" "<<s<<endl;
    if(s > 0.48) return 2;
    else if (s==0.48) return 1;//(abs(s-0.48) < 1e6) return 1;
    else return 0;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(10);
    cin>>n>>m; double s;
    for (int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j]; s+=a[i][j];
        }
    }
    if(abs(s/(n*m) - 0.48) < 1e-7){
        cout<<"correctly exposed";
        return 0;
    }
    else if(s/(n*m) > 0.48){
        cout<<"overexposed"<<endl;
        double l = 0, r=1, mid; int res=0;
        while(r>=l && res!=1){
            mid = (l+r)/2;
            res =(check(mid));//{
            if(res == 2){
                r = mid-0.00000001;
            }
            else{
                l = mid+0.00000001;
            }
        }
        cout<<mid<<endl;
    }
    else{
        cout<<"underexposed"<<endl;
        double l = 1, r=100000, mid; int res=0;
        while(r>=l && res!=1){
            mid = (l+r)/2;
            int res =(check(mid));//{
            if(res == 2){
                r = mid-0.00000001;
            }
            else{
                l = mid+0.00000001;
            }
        }
         cout<<mid<<endl;
    }



}
