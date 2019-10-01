#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main(){
  unsigned int x;
  vector<unsigned int> all;
  int ct =0;
  while(cin >> x){
    ct++;
    all.push_back(x);
    if(ct % 2 == 1){
      int n = ct/2;
      nth_element(all.begin(), all.begin() +n, all.end());
      cout << all[n] << endl;
    } else {
      int n1 = ct/2;
      int n2 = ct/2 -1;
      nth_element(all.begin(), all.begin() +n1, all.end());
      int a1 = all[n1];
      nth_element(all.begin(), all.begin() +n2, all.end());
      int a2= all[n2];
      cout << ((a1 + a2) >> 1) << endl;
    }
  }

}
