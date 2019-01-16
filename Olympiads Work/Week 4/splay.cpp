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

struct node{
    node *l,*r;
    int key;
};
struct node* Create(int key){
    struct node* node = new struct node;
    node->key=key;
    node->l=node->r=NULL; return (node);
};
node* LeftR(node *x){
    node *temp = x->r;
    x -> r = temp->l;
    temp->l = x;
    return temp;
};
node* RightR(node *x){
    node *temp = x->l;
    x->l = temp->r;
    temp->r=x;
    return temp;
}
node* Splay(node *rt, int key){
    if(rt==NULL||rt->key==key)
        return rt;
    if(rt->key >key){
        if(rt->l==NULL)
            return rt;
        if(rt->l->key>key){
            rt->l->l=Splay(rt->l->l,key);
            rt=RightR(rt);
        }
        else if (rt->l->key<key){
            rt->l->r=Splay(rt->l->r,key);
            if(rt->l->r!=NULL)
                rt->l=LeftR(rt->l);
        }
        return (rt->l!=NULL?RightR(rt):rt);
    }
    else{
        if(rt->r==NULL)
            return rt;
        if(rt->r->key>key){
            rt->r->l=Splay(rt->r->l,key);
            if(rt->r->l!=NULL)
                rt->r=RightR(rt->r);
            }else if(rt->r->key<key){
                rt->r->r=Splay(rt->r->r,key);
                rt=LeftR(rt);
            }
            return(rt->r!=NULL?LeftR(rt):rt);
    }
}
node *Find(node *rt, int key){
    return Splay(rt,key);
}
node *Insert(node *rt, int key){
    if(rt==NULL) return Create(key);
    rt=Splay(rt,key);
    if(rt->key == key)
        return rt;
    node* t = Create(key);
    if(rt->key>key){
        t->r=rt;
        t->l=rt->l;
        rt->l=NULL;
    }
    else{
        t->l=rt;
        t->r=rt->r;
        rt->r=NULL;
    }
    return t;
}
node *Delete(node *rt, int key){
    node *t;
    if(rt==NULL) return rt;
    rt=Splay(rt,key);
    if(key!=rt->key) return rt;
    if(rt->l==NULL){
        t=rt; rt=rt->r;
    }else{
        t=rt;
        rt=Splay(rt->l,key);
        rt->r=t->r;
    }
    delete(t);
    return rt;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i =0; i < n; i++){

    }



}
