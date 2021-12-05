#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

bool findOrInsert(int x, int y, map<ii, int> &seen) {
  auto found = seen.find(make_pair(x, y));
  if (found == seen.end()) {
    seen[make_pair(x, y)] = 1;
    return false;
  }
  found->second++;
  return found->second == 2;
}

int main() {
  string l;
  map<ii, int> seen;
  int out = 0;
  while (getline(cin, l)) {
    int x1, y1;
    int x2, y2;
    sscanf(l.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
    if (y1 == y2) {
      int low = min(x1, x2);
      int high = max(x1, x2);
      for (int i = low; i <= high; i++)
        if (findOrInsert(i, y1, seen))
          out++;
    } else if (x1 == x2) {
      int low = min(y1, y2);
      int high = max(y1, y2);
      for (int i = low; i <= high; i++)
        if (findOrInsert(x1, i, seen))
          out++;
    }
  }
  cout << out << endl;
}
