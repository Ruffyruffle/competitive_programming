#include <iostream>
#include <set>
#include <vector>

int g, p;
using namespace std;
vector<int> planes;
set<int> gates;

int main() {
  cin>>g>>p;
  int a;
  bool s = false;
  for(int i = 0; i < p; i++){
    cin>>a;
    planes.push_back(-a);
  }
  for(int i = 1; i < g+1; i++){
    gates.insert(-i);
  }
  //cout<<planes[0];
  for(int i = 0; i < p; i++){
    //int l = *gates.upper_bound(planes[i]);
    //cout<<"a"<<l<< endl;
    if (gates.lower_bound(planes[i]) == gates.end()){
      cout<<i;
      s = true;
      break;
    }
    gates.erase(gates.lower_bound(planes[i]));
  }
  if (!s)
    cout<<p;
}
