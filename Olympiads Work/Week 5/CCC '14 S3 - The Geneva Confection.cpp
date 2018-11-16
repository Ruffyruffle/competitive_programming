#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
#define MAXN 1000000
using namespace std;
int n;

bool solve(){
    stack<int> b;
    stack<int> t;
    int c = 1, n,x;
    cin>>n;
    for(int i = 0 ; i < n; i++){
        cin>>x;
        t.push(x);
    }
    while(!t.empty()){
        if(t.top() == c){
            t.pop(); c++;
        }
        else if(!b.empty() && b.top() == c){
            b.pop(); c++;
        }
        else{
            x = t.top(); t.pop(); b.push(x);
        }
    }
    while(!b.empty()){
        x = b.top(); if(x == c) c++;
        b.pop();
    }
    return (c-1==n);
}

int main(){
    cin>>n;
    for (int i =0; i < n; i++){
        cout<<(solve() ? "Y" : "N")<<endl;
    }
}
