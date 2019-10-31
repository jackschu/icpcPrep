#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
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

int main() {
  vi ns;
  ns.reserve(900);
  for (int a = 1; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        ns.push_back(a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a);
      }
    }
  }
  sort(ns.begin(), ns.end());
  int n;
  cin >> n;
  for (int ic = 0; ic < n; ic++) {
    int x;
    cin >> x;
    auto f = lower_bound(ns.begin(), ns.end(), x);
    int out = -1;
    int dist;
    if (f != ns.end()) {
      out = *f;
      dist = out - x;
    }
    if (f != ns.begin()) {
      int j = distance(ns.begin(), f);
      int opt = ns[j - 1];
      int dist1 = x - opt;
      if (out == -1 || dist1 <= dist) {
        out = opt;
      }
    }
    cout << out << endl;
  }
}
