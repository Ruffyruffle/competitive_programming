#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl "\n"
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;
map<string, int> a;
int in[3], d[3];
string k[3];
string ans = "";

int check(int x, int y){
    if (d[0] == x && d[1] == y)
        return 0;
    else if (d[0] == y && d[2] == x)
        return 1;
    else if (d[1] == x && d[2] == y)
        return 2;
    else return -1;
}

int main(){
    a["A"] = 1; a["A#"] = 2; a["B"] = 3; a["C"] = 4; a["C#"] = 5; a["D"] = 6;
    a["D#"] = 7; a["E"] = 8; a["F"] = 9; a["F#"] = 10; a["G"] = 11; a["G#"] = 12;
    string b;
    for(int i = 0; i < 3; i++){
        getline(cin, b);
        k[i] = b;
        in[i] = a[b];
    }
    d[0] = min(abs(in[0] - in[1]), 12 - abs(in[0] - in[1]));
    d[1] = min(abs(in[1] - in[2]), 12 - abs(in[1] - in[2]));
    d[2] = min(abs(in[0] - in[2]), 12 - abs(in[0] - in[2]));

    int t = check(4,3);
    if(t!=-1){
        ans+= "\nmajor";
        if(t == 0) {
            ans += "\nroot position";
            ans = k[0] + ans;
        }
        if(t == 1) {
            ans += "\nfirst inversion";
            ans = k[2] + ans;
        }
        if(t == 2) {
            ans += "\nsecond inversion";
            ans = k[1] + ans;
        }
        cout<<ans;
        return 0;
    }
    t = check(3,4);
    if(t!=-1){
        ans+= "\nminor";
        if(t == 0) {
            ans += "\nroot position";
            ans = k[0] + ans;
        }
        if(t == 1) {
            ans += "\nfirst inversion";
            ans = k[2] + ans;
        }
        if(t == 2) {
            ans += "\nsecond inversion";
            ans = k[1] + ans;
        }
        cout<<ans;
        return 0;
    }
    t = check(3,3);
        if(t!=-1){
        ans+= "\ndiminished";
        if(t == 0) {
            ans += "\nroot position";
            ans = k[0] + ans;
        }
        if(t == 1) {
            ans += "\nfirst inversion";
            ans = k[2] + ans;
        }
        if(t == 2) {
            ans += "\nsecond inversion";
            ans = k[1] + ans;
        }
        cout<<ans;
        return 0;
    }
    t = check(4,4);
        if(t!=-1){
        ans+= "\naugmented";
        if(t == 0) {
            ans += "\nroot position";
            ans = k[0] + ans;
        }
        else if(t == 1) {
            ans += "\nfirst inversion";
            ans = k[2] + ans;
        }
        else if(t == 2) {
            ans += "\nsecond inversion";
            ans = k[1] + ans;
        }
        cout<<ans;
        return 0;
    }
}
