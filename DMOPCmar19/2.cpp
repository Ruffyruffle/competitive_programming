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
string a[4], b[4];
bool solve3(string *a){
    bool t=1;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]) t=0;
    }

    if(t) return 1;
    string c[4];
    t=1;
    for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    // 3 1 2
    c[3] = a[1]; c[2] = a[3]; c[1] = a[2];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    t=1;
        c[3] = a[2]; c[2] = a[1]; c[1] = a[3];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
        //cout<<b[i]<<" "<<c[i]<<endl;;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[3]; c[2] = a[0]; c[3] = a[2];

    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[2]; c[2] = a[3]; c[3] = a[0];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }

        c[0] = a[3]; c[1] = a[0]; c[3] = a[1];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[1]; c[1] = a[3]; c[3] = a[0];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    //0 1 2//2 0 1// 1 2 0

        c[0] = a[2]; c[1] = a[0]; c[2] = a[1];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
     c[0] = a[1]; c[1] = a[2]; c[2] = a[0];
    for(int i = 0; i < 4; i++){
        if(c[i] != b[i]) t=0;
    }
    if(t) return 1;
    t=1;

    return 0;
}

bool solve(string *a){
    bool t=1;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]) t=0;
    }

    if(t) return 1;
    string c[4];
    t=1;
    for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    // 3 1 2
    c[3] = a[1]; c[2] = a[3]; c[1] = a[2];
    t=solve3(c);
    if(t) return 1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    t=1;
        c[3] = a[2]; c[2] = a[1]; c[1] = a[3];
    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[3]; c[2] = a[0]; c[3] = a[2];

    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[2]; c[2] = a[3]; c[3] = a[0];
    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }

        c[0] = a[3]; c[1] = a[0]; c[3] = a[1];
    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
        c[0] = a[1]; c[1] = a[3]; c[3] = a[0];
    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
    //0 1 2//2 0 1// 1 2 0

        c[0] = a[2]; c[1] = a[0]; c[2] = a[1];
    t=solve3(c);
    if(t) return 1;
    t=1;
     for(int i =0; i < 4; i++){
        c[i] = a[i];
    }
     c[0] = a[1]; c[1] = a[2]; c[2] = a[0];
    t=solve3(c);
    if(t) return 1;
    t=1;

    return 0;
}

bool solve2(){
    string c[4];
    bool t=1;
    for(int i =0; i < 4; i++){
        for(int j = 0;  j < 4; j++){
            for(int k =0; k < 4; k++){
                c[k] = a[k];
            }
            if(i!=j) swap(c[i], c[j]);
            t=solve(c);
            if(t) return 1;
        }
    }
    return 0;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i =0; i < 4; i++){
        cin>>a[i];
    }for (int i =0; i < 4; i++){
        cin>>b[i];
    }
    bool iden = solve(a);
    bool re = solve2();
    cout<<(!iden&&re?"YES":"NO");





}
