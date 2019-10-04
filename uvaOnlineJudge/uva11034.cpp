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
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

void run_case() {
  int mxl, m;
  cin >>mxl >> m;
  mxl *= 100;
  queue<int> l;
  queue<int> r;
  for (int i = 0; i < m; i++) {
    DEBUG cout << "i " << i << endl;
    int x;
    string s;
    cin >> x;
    cin >> s;
    if (s == "left") {
      l.push(x);
    } else {
      r.push(x);
    }
  }
  int ct = 0;
  bool is_left = true;
  while(!l.empty() || !r.empty()){
    DEBUG cout << l.size() << r.size() << endl;
    queue<int> &cur = is_left ? l: r;
    //queue<int> &other = is_left? r: l;
    int spc = mxl;
    while(!cur.empty()){
      if (spc >= cur.front()){
	spc -= cur.front();
	cur.pop();
      } else 
	break;
    }
    ct++;
    is_left = !is_left;
  }
  cout << ct << endl;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    run_case();
  }
}
