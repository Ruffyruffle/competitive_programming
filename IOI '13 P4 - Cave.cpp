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
#define MAXN 5001
using namespace std;
int n,m,ans,k;
pii known[MAXN];
int guess[MAXN];
int S[MAXN], D[MAXN];
//int call=0;

bool check(int &l, int &r, int &i, int pos){
    for(int j = 0; j < n; j++){
        if((r >= j && j>=l))guess[j]=pos;
        else guess[j]=pos^1;
    }
    for(int j = 0; j < i; j++){
        guess[known[j].f]=known[j].s;
    }
    int a = tryCombination(guess);


    //assert(70000>=++call);
//
//    cout<<i<<" "<<known[0].f<<" "<<known[0].s<<endl;
//
//
//    for(int i = 0; i < n; i++){
//        cout<<guess[i]<<" ";
//    }
//    int a; cin>>a;
//    cout<<endl;

    return (a==-1||a>i);
}

//void debug(int *a, int *b){
//    cout<<'a'<<endl;
//    for(int i = 0; i  <n; i++){
//    cout<<a[i]<<" ";}cout<<endl;
//    for(int i =0; i <n; i++){
//        cout<<b[i]<<" ";}cout<<endl;
//}

void exploreCave(int N){
    n=N;
    for(int i =0; i < N; i++){
        int l=0,r=N-1,mid,pos;

        if(check(l,r,i,0)) pos=0;
        else pos=1;

        while(l<=r){
            mid = (l+r)>>1;
            if(check(l, mid, i,pos)){
                r=mid-1;
            }
            else l = mid+1;
        }
        known[i] = {l,pos};
        S[l] = pos;
        D[l]=i;
        //cout<<"door, switch, state"<<i<<" "<<l<<" "<<pos<<endl;
    //debug(S,D);
    }
    answer(S,D);
}

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    exploreCave(4);
}
