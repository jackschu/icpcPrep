#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int m;
ii last;
int taken;
vii opts;
int matches(int a, ii b) {
  if (a == b.first)
    return b.second;
  if (a == b.second)
    return b.first;
  return -1;
}

bool backtrack(int c, int match) {
  DEBUG printf("c %d m%d\n", c, match);
  if (c == n) {
    if (match == last.first)
      return true;
    return false;
  }

  for (int i = 0; i < m; i++) {
    if (taken & 1 << i)
      continue;
    int got = matches(match, opts[i]);
    if (got == -1)
      continue;
    taken |= 1 << i;
    if (backtrack(c + 1, got))
      return true;
    taken ^= 1 << i;
  }

  return false;
}

int main() {
  cin >> n;
  opts.assign(20, ii(0, 0));
  while (n) {
    taken = 0;
    cin >> m;

    int a, b;
    cin >> a >> b;
    ii start = ii(a, b);
    cin >> a >> b;
    last = ii(a, b);

    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      opts[i] = ii(a, b);
    }
    cout << (backtrack(0, start.second) ? "YES" : "NO") << std::endl;
    cin >> n;
  }
}
