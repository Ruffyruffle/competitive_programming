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
int n,k;
string ans = "1";
vector<string> a;

string addStr(string a, string b){
    string sum = "";
    int length = max(a.length(), b.length());

    while (a.size() < length){
        a = "0" + a;
    }
    while (b.size() < length){
        b = "0" + b;
    }
    int c = 0;
    int dsum = 0;

    for (int i = length-1; i > -1; i--){
        dsum = int(a[i] - '0') + int(b[i] - '0') + c;
        c = 0;
        if (dsum > 9 ){
            dsum -=10;
            c = 1;
        }
        sum = (to_string(dsum)) + sum;

    }
    if (c == 1){
        sum = "1" + sum;
    }
    //cout<<sum;
    return sum;
}
string subtStr(string n1, string n2){
    int length = max(n1.size(), n2.size());

     while (n1.size() < length){
        n1 = "0" + n1;
    }
    while (n2.size() < length){
        n2 = "0" + n2;
    }

    string diff = "";
    int a = 0;
    for (int i = length-1; i > -1; i--) {
        a = (n1[i]-'0') - (n2[i]-'0');

        if (a>-1){
            diff = to_string(a) + diff;
        }
        else{
            int b = i-1;
            while (b > -1){
                n1[b] = ((n1[b]-'0') - 1) % 10 + '0';
                if (n1[b] == '9')
                    b--;
                else
                    break;
            }
                    diff = to_string(a+10) + diff;
        }

    }
        return diff.erase(0, min(diff.find_first_not_of('0'), diff.size()-1));
}

string kar(string x, string y){
    bool f = 0;
    if(x[0] == '-' || y[0] == '-' && !(x[0] == '-' && y[0] == '-'))
        f = 1;
    int length = max(x.length(), y.length());

    while (x.size() < length){
        x = "0" + x;
    }
    while (y.size() < length){
        y = "0" + y;
    }
    if (length < 8){
        ll f;
        f = (stoll((x)) * (stoll(y)));
        return to_string(f);
    }

    string x1 = x.substr(0,length/2);
    string x2 = x.substr(length/2,length-length/2);
    string y1 = y.substr(0,length/2);
    string y2 = y.substr(length/2,length-length/2);

    string z0 = kar(x1, y1);
    string z1 = kar(x2, y2);
    string z2 = kar(addStr(x1,x2), addStr(y1,y2));
    string z3 = subtStr(z2,addStr(z0, z1));
    for (int i = 0; i < 2 * (length - length/2); i++){
        z0 += "0";
    }
    for (int  i = 0; i < (length - length/2); i++){
        z3 += "0";
    }

    string product = addStr(addStr(z0, z1), z3);

    if(f) return "-" + product.erase(0, min(product.find_first_not_of('0'), product.size()-1));
    return product.erase(0, min(product.find_first_not_of('0'), product.size()-1));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    string x;
    for (int i =0; i < n; i++){
        cin>>x;
        a.pb(x);
    }
    cout<<kar(a[0],a[1]);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
    while(k > 0){
        if(k > 1){
            if(stoll(a[0]) * stoll(a[1]) > stoll(a[a.size() - 1]) * stoll(a[a.size() - 2])){
                ans = kar(ans,a[0]);
                ans = kar(ans,a[1]);
                a.erase(a.begin()); a.erase(a.begin());
            }
            else{
                ans = kar(ans, a[a.size() - 1]);
                ans = kar(ans, a[a.size() - 2]);
                a.erase(a.end()-1); a.erase(a.end()-1);
            }
        }
        else{
            ans = kar(ans, a[0]);
        }
        k-=2;
    }
    cout<<ans<<endl;
}
