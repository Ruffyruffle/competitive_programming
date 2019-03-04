#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000002
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
int n,m,k,ans;
int a[3][3], b[3] ,c[3];

void t(){
    for(int z = 0; z < 3; z++){
        int dif =0;
        for(int i =0; i < 3; i++){
            if(b[i] >= 2){
                int last = INF;
                for(int j = 0; j < 3; j++){
                    if(a[i][j] != INF){
                        if(last != INF){
                            dif = (a[i][j] - a[i][last]) / (j-last);
                        }
                        else last = j;
                    }
                }
                int base;
                if(a[i][0] != INF){
                    base = a[i][0];
                }
                else base = a[i][1] - dif;
                for(int k=0;k < 3; k++){
                    a[i][k] = base + dif*k;
                }
                b[i] = 3;
            }
        }
        for(int i =0; i < 3; i++){
            if(c[i]>=2){
                int last = INF;
                for(int j = 0; j < 3; j++){
                    if(a[j][i] != INF){
                        if(last != INF){
                            dif = (a[j][i] - a[last][i]) / (j-last);
                        }
                        else last = j;
                    }
                }
                int base;
                if(a[0][i] != INF){
                    base = a[0][i];
                }
                else base = a[1][i] - dif;
                for(int k=0;k < 3; k++){
                    a[k][i] = base + dif*k;
                }
                c[i] = 3;
            }
        }
    }
}

void cou(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            b[i] = 0; c[i] = 0;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i][j] != INF){
                b[i]++;
                c[j]++;
            }
        }
    }
}

//void fillh(){
//    for(int i = 0; i < 3; i++){
//        bool x=0; int f=0x3f3f3f3f;
//        for(int j=0;j<3;j++){
//            if(a[i][j] == INF) x=1;
//            else f=a[i][j];
//        }
//        if(x && f!= (0x3f3f3f3f)){
//            for(int j = 0; j < 3; j++){
//                a[i][j] = f;
//            }
//            break;
//        }
//    }
//}
//void fillv(){
//    for(int i = 0; i < 3; i++){
//        bool x=0; int f=0x3f3f3f3f;
//        for(int j=0;j<3;j++){
//            if(a[j][i] == INF) x=1;
//            else f=a[j][i];
//        }
//        if(x && f!= (0x3f3f3f3f)){
//            for(int j = 0; j < 3; j++){
//                a[j][i] = f;
//            }
//            break;
//        }
//    }
//}
void fix(int i, int j){
    if(a[i][j]!=INF) return;
    a[i][j] = 0;
    cou();
    t();
    cou();
    t();
    cou();
    t();
}

int main(){
    string x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>x;
            if(x == "X"){
                a[i][j] = INF;
                //cout<<"a"<<endl;
            }
            else {
                    a[i][j] = stoi(x);
                    b[i]++;
                    c[j]++;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        cou();
        t();
    }
    //for(int i = 0; i < 3; i++){
    fix(1,1);
    fix(0,1);
    fix(1,0);
    fix(2,1);
    fix(1,2);
    fix(0,0);fix(0,2);fix(2,0);fix(2,2);
//
//    for(int i = 0; i < 3; i++){
//        fillh();
//        cou();
//        t();
//    }
//    for(int i = 0; i < 3; i++){
//        fillv();
//        cou();
//        t();
//    }

    bool dd=0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            if(a[i][j] == INF) dd=1;
        }
    }

    if(dd){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3;j++){
                a[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
