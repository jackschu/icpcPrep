#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#define DEBUG if (false)
using namespace std;


void run_case(int tc){
  queue<int> bag;
  set<int> has;
  int mx = 0;
  for(int i = 0 ; i < tc; i++){
    int x;
    cin >> x;
    auto found =has.find(x);
    if(found == has.end()){
      has.insert(x);
      bag.push(x);
    } else {
      while(!bag.empty() && bag.front() != x){
	has.erase(bag.front());
	bag.pop();
      }
      if(!bag.empty()){
      	bag.pop();
      }
      has.insert(x);
      bag.push(x);
    }
    mx = max(mx, (int)bag.size());
  }
  cout << mx << endl;
}

int main() {
  int tc;
  cin >> tc;
  for(int i = 0; i< tc; i++){
    int x; cin>>x;
    run_case(x);
  }
}
