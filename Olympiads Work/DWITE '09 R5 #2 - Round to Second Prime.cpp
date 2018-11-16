#include <bits/stdc++.h>
using namespace std;
set<int> a;

void preCalc(){
    a.insert(1);
    a.insert(2);
    for(int i = 3; i <= 100; i++){
            bool d = true;
        for(int j = 2; j < sqrt(i)+1; j++){
            if(i % j == 0){
                d = false;
                break;
            }
        }
        if(d) a.insert(i);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    preCalc();
    for(int i = 0; i < 5; i++){
        int c = 0; cin>>c;
        auto b = a.upper_bound(c);
        auto d = ++b; auto e = --b; --e; --e;
        if(*a.lower_bound(c) == c) --e;
        cout<<((abs(*d-c) > abs(*e-c)) ? *e:*d);
        cout<<"\n";
    }
}
