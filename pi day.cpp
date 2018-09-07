#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int n, k;
int dp[251][251][251];

int pie(int people, int line, int pies){
    if (people == 0)
        return 0;
    if (pies>line)
        return 0;
    if (people==line)
        return 1;
    if (dp[people][line][pies] != -1)
        return dp[people][line][pies];

    int com = 0;

    for(int i = pies; i <= line; i++){
        com+= pie(people - 1,line-i,i);
    }
    return com;
}

int main(){
    cin>>n>>k;

    memset(dp,-1,sizeof(dp));

    cout<< pie(k,n,1);
}
