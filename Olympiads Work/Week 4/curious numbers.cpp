#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using namespace std;

ll q, k, x, y;
vector<ll> vec;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>q>>k;
    for (int i = 0; i < 100001; i++) {
        string s1 = to_string(i), s2 = s1, s = "";
        reverse(s2.begin(), s2.end());
        s = s1 + s2;
        ll t = stoll(s);
        if (t % k == 0) vec.push_back(t);
        s1.pop_back();
        s = s1+s2;
        t = stoll(s);
        if(t%k == 0 ) vec.push_back(t);
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i < q; i++) {
        cin>>x>>y;
        cout<<(upper_bound(vec.begin(), vec.end(), y) - lower_bound(vec.begin(), vec.end(), x)) << "\n";
    }
}
