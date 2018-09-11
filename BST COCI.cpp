#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <map>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 300001
using namespace std;
int n;
ll C = 0;
//struct node{
//    int key;
//    node *lc, *rc;
//};
//node *create(int a){
//    node *b = (node*)malloc(sizeof(node));
//    b->key = a;
//    b->lc = NULL;
//    b->rc = NULL;
//    return b;
//};
//node *add(node *node, int key){
//    C++;
//    if (node == NULL){
//        return create(key);
//    }
//    if (key<node->key){
//        if (node->lc == NULL)
//            node->lc=create(key);
//        else
//            return add(node->lc, key);
//    }
//    else if (key>node->key){
//        if (node->rc == NULL)
//            node->rc=create(key);
//        else
//            return add(node->rc,key);
//    }
//    return node;
//};

int main(){
    map<int, int> f;
    cin.sync_with_stdio(0);
    cin.tie(0);<
    int c,h;
    cin>>n;
    //struct node *root = NULL;
    //root = add(root, c);

    //cout<<"a"<<C<<"a";
    //cout<<C<<endl;
    for (int i =0; i < n; i++){
        cin>>c;
        h = 0;
        map<int, int>::iterator it = f.lower_bound(c);
        if(it != f.end())
            h = it->second+1;
        if(it != f.begin()){
            reverse_iterator<map<int, int>::iterator> itr(it);
            h = max(h, itr->second+1);
        }
        C+=h;
        f[c] = h;
        //add(root, c);
        //cout<<"a"<<C<<"a";
        cout<<C<<endl;
    }
    //inDFS(root);
}
