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

ll mem[51][51][2][51];
int n, k, m;

ll calc(int sz, int run, int last, int bars) {
  if (bars > k)
    return 0;
  if (sz == n) {
    if (bars == k)
      return 1;
    return 0;
  }
  if (mem[sz][run][last][bars] != -1)
    return mem[sz][run][last][bars];
  ll out = 0;
  if (run < m) {
    out += calc(sz + 1, run + 1, last, bars);
  }
  out += calc(sz + 1, 1, (last + 1) % 2, bars + 1);
  return mem[sz][run][last][bars] = out;
}

int main() {
  while (cin >> n >> k >> m) {
    memset(mem, -1, sizeof mem);
    cout << calc(1, 1, 1, 1) << endl;
  }
}
