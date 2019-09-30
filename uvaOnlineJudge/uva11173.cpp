#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#define DEBUG if(false)
using namespace std;

int main(){
  int tc;
  cin >> tc;
  for(int i =0; i <tc; i++){
    int n, k;
    cin >>n >> k;
    cout << (k^(k>>1)) << endl;
  }
}
