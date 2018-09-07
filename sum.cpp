#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int main(){
    freopen("double_sum_100000.txt", "r", stdin);
    int n,a,dif,e,r;
    int g;
    cin>>n;
    int nums[1000000];
    int index[1000000];
    memset(nums, 0, sizeof(nums));
    memset(index, 0, sizeof(index));

    for (int i = 0; i < n; i++){
        cin>>a;
        nums[a] = 1;
        index[a] = i;
    }
    cin>>g;

    for(int i = 0; i < n-1; i++){
        if (nums[i] >0){
            dif = g - i;
            if (nums[dif]>0){
                //e = index[i];
                //r = index[dif];
                //cout<<i<<" "<<dif<<endl;
                cout<< index[i] <<" " << index[dif]<<endl;
                //break;
            }
        }
    }
    //cout<<min(e,r)<<" "<<max(e,r);
}
