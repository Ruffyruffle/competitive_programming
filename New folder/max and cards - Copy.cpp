#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;

using namespace std;

ll q, k, x, y;
vector<ll> vec;

int main() {
    cin>>q>>k;
    for (int i = 0; i < 1000001; i++) {
        string s1 = to_string(i), s2 = s1, s = "";
        reverse(s2.begin(), s2.end());
        s = s1 + s2;
        ll t = stoll(s);
        if (t % k == 0) vec.push_back(t);
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i <= q; i++) {
        cin>>x>>y;
        cout<< upper_bound(vec.begin(), vec.end(), y) - lower_bound(vec.begin(), vec.end(), x) << "\n";
    }
}
