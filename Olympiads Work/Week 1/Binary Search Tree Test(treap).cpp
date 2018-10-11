#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include<stack>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 100000
using namespace std;
int n,m;
ll v;
int c = 0;
bool found = false;
struct node{
    ll key, pri;
    node *lc;
    node *rc;
};
node *zigL(node *root){
    node *newRoot = root->rc;
    node *left = newRoot->lc;

    newRoot->lc = root;
    root ->rc = left;
    return newRoot;
}
node *zigR(node *root){
    node *newRoot = root->lc;
    node *right = newRoot ->rc;

    newRoot -> rc = root;
    root-> lc = right;
    return newRoot;
}

node *newNode(int key){
    node *temp = new node;
    temp->key = key;
    temp->pri = rand()%3000000;
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
}

node *add(int key, node *root){
    if(root == NULL)
        return newNode(key);

    if (root -> key >= key){
        root->lc = add(key, root->lc);

        if(root->lc->pri > root-> pri)
            root = zigR(root);
    }
    else{
        root->rc = add(key, root->rc);

     if (root->rc->pri > root->pri){
        root = zigL(root);
     }
    }
    return root;
}
node *Remove(int key, node *root){
    if (root == NULL)
        return root;
    if (key == root->key){
        if (root->lc == NULL){
            node *tmp = root->rc;
            delete(root);
            root = tmp;
        }
        else if(root->rc == NULL){
            node *tmp = root->lc;
            delete(root);
            root = tmp;
        }
        else if(root->rc->pri > root->lc->pri){
            root = zigL(root);
            root->lc = Remove(key, root->lc);
        }
        else{
            root = zigR(root);
            root->rc = Remove(key, root->rc);
        }
    }
    else if (key>root->key)
        root->rc = Remove(key, root->rc);
    else if (key<root->key)
        root->lc = Remove(key, root->lc);
    return root;
}

node *small(node *root,int *n, int k){
    node *tmp = root;
    if (root->lc != NULL && *n<k)
        tmp = small(root->lc,n,k);
    //cout<<*n<<endl;
    *n = *n+1;
    //cout<<*n<<endl;

    if(*n==k)
        tmp = root;

    if (root->rc != NULL && *n<k)
        tmp = small(root->rc,n,k);
    return tmp;
}
node *Search(node *root, int k){
    node *tmp = NULL;
    c++;
    if (root->lc != NULL)
        tmp = Search(root->lc,k);

    if (root->key == k){
        found = true;
        return root;
    }

    if (root->rc != NULL)
        tmp = Search(root->rc,k);
    return tmp;
}

void out(node* root)
{
    if (root != NULL)
    {
        out(root->lc);
        cout<<root->key<<" ";
        out(root->rc);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll b;
    char o;
    node *root = NULL;
    ll last = 0;
    for (int i =0; i < n; i++){
        cin>>b;
        root = add(b, root);
    }

    for(int i = 0; i < m; i++){
        cin>>o>>v;
        v = v^last;
        if (o == 'I')
            root = add(v, root);
        else if (o == 'R')
            root = Remove(v, root);
        else if (o == 'S'){
            int *f = new int;
            *f = 0;
            last = small(root,f,v)->key;
            cout<<(last)<<endl;
        }
        else if (o == 'L'){
            c = -1;
            found = false;
            Search(root, v);
            last = c;
            if (found)
                cout<<last<<endl;
            else{
                cout<<"-1"<<endl;
                last = -1;
            }
        }
    }
    out(root);
}
