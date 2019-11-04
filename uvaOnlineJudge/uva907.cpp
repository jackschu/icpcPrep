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
vi costs;
int memo[602][302];
int inf = 1e9;
vi sums;
int bt(int site, int nights) {
  if (nights == 0)
    return memo[site][nights] = sums[site];
  if (nights < 0)
    return inf;
  if (memo[site][nights] != -1)
    return memo[site][nights];
  int sum = -costs[site];
  int out = inf;
  for (int i = site; i >= 0; i--) {
    sum += costs[i];
    if (sum >= out)
      break;
    int opt = max(sum, bt(i, nights - 1));
    if (opt < out)
      out = opt;
  }
  return memo[site][nights] = out;
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    costs.clear();
    sums.clear();
    costs.reserve(n + 1);
    sums.reserve(n + 2);
    sums.push_back(0);
    int sum = 0;
    for (int i = 0; i < n + 1; i++) {
      int x;
      cin >> x;
      sum += x;
      costs.push_back(x);
      sums.push_back(sum);
    }

    memset(memo, -1, sizeof memo);
    cout << bt(n + 1, k) << endl;
  }
}
