#include <iostream>
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <functional>
#define endl '\n'
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ll n,m,v,j;
ordered_set bst;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll b;
    char o;
    ll last = 0;
    for (int i =0; i < n; i++){
        cin>>b;
        bst.insert(b);
    }
    for(int i = 0; i < m; i++){
        cin>>o>>v;
        v ^=last;
        if (o == 'I'){
            bst.insert(v);
        }
        else if (o == 'R'){
            bst.erase(--bst.lower_bound(v));
        }
        else if (o == 'S'){
            j = *bst.find_by_order(v-1);
            last = j;
            cout<<j<<endl;
        }
        else if (o == 'L'){
            //j = distance(bst.begin(), find(bst.begin(),bst.end(),v));
            last = (bst.lower_bound(v) == bst.begin() ? -1: bst.order_of_key(v) + 1);
            cout<<last << endl;
        }
    }
       for (ordered_set::iterator it=bst.begin(); it!=bst.end(); ++it) cout<<*it<<" ";
}
