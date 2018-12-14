/*
ID: stevenu1
LANG: C++
TASK: friday
*/

#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
int co[7];

int main(){
    freopen ("friday.in","r",stdin);
    freopen ("friday.out","w",stdout);

    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    bool leap;
    int ans = 0;
    int day = 2;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    ldays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1900; i < 1900 + n; i++){
        if(i % 4 == 0 && (!(i % 100 == 0) || i % 400 == 0)){
           leap = 1;
        }
        else{
            leap = 0;
        }
        for(int j = 0; j < 12; j++){
            int cday = 0;
            int mday = (leap?ldays[j] : days[j]);
            for(int d = 0; d < mday; d++){
                if(cday++ == 12){
                    co[day++ % 7]++;
                }else day++;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        cout<<co[i]<<(i==6 ? "" : " ");
    }
    cout<<endl;

    return 0;
}
