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

void run_case() {
  int n, g, b;
  cin >> n >> g >> b;
  vector<int> tempg;
  tempg.reserve(g);
  copy_n(istream_iterator<int>(cin), g, back_inserter(tempg));
  multiset<int, greater<int>> gs(tempg.begin(), tempg.end());
  vector<int> tempb;
  tempb.reserve(b);
  copy_n(istream_iterator<int>(cin), b, back_inserter(tempb));
  multiset<int, greater<int>> bs(tempb.begin(), tempb.end());

  while (!bs.empty() && !gs.empty()) {
    vector<int> bs_next;
    vector<int> gs_next;
    for (int i = 0; i < n; i++) {
      if (bs.empty() || gs.empty())
        break;
      int bf = *bs.begin();
      int gf = *gs.begin();
      if (bf > gf) {
        bs_next.push_back(bf - gf);
      } else if (gf > bf) {
        gs_next.push_back(gf - bf);
      }
      bs.erase(bs.begin());
      gs.erase(gs.begin());
    }
    for (auto elem : bs_next) {
      bs.insert(elem);
    }
    for (auto elem : gs_next) {
      gs.insert(elem);
    }
  }
  if (!bs.empty()) {
    cout << "blue wins" << endl;
    for (auto elem : bs) {
      cout << elem << endl;
    }
  } else if (!gs.empty()) {
    cout << "green wins" << endl;
    for (auto elem : gs) {
      cout << elem << endl;
    }
  } else {
    cout << "green and blue died" << endl;
  }
}

int main() {
  int tc;
  cin >> tc;
  bool first = true;
  for (int i = 0; i < tc; i++) {
    if (!first)
      cout << endl;
    first = false;
    run_case();
  }
}
