#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
ll mod = 1e9+7;
ll n,m,ans,ans2;
int c;
vector<int> a;
void primeFactors(int n)
{
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}

void solve(int n){
    while(n%2==0){
        a.pb(2); n/=2;
    }
    for (int i =3; i<=sqrt(n); i+=2){
        while(n%i==0){
            a.pb(i); n/=i;
        }
    }
    if(n>2) a.pb(n);
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s,ss;
    unordered_map<char,int> a,b;
    cin>>ss>>s;
    for(char i : s){
        if(!a[i])
            a[i] = 1;
        else{
            a[i]++;
        }
    }
    for(char i : ss){
        if(!a[i])
            a[i] = 1;
        else{
            a[i]++;
        }
    }





}
