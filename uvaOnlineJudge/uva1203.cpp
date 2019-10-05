#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

struct q {
  int up;
  int p;
  int id;
  q(int id, int p) : up(p), p(p), id(id) {}
  bool operator<(const q &j) const {
  if(up!=j.up) return up > j.up;
  return id > j.id;
  }
};

  
int main(){
  string l;
  cin >> l;
  priority_queue<q> pq;
  while (l != "#") {
    int id;
    int p;
    cin >> id;
    cin >> p;
    pq.emplace(id, p);
    cin>> l;
  }
  int k;
  cin>> k;
  for(int i = 0; i < k; i++){
    auto cur = pq.top();
    pq.pop();
    cout << cur.id << endl;
    cur.up += cur.p;
    pq.push(cur);
  }
    
}
