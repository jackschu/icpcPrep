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
long long mem[202][12][22];
int d, n, m;
vi nums;
long long backtrack(int idx, int taken, int rem) {
  DEBUG printf("idx %d tak %d rem %d\n", idx, taken, rem);
  if (rem < 0)
    rem += d;
  if (idx > n)
    return 0;
  if (taken == m) {
    if (rem == 0) {
      mem[idx][taken][rem] = 1;
      DEBUG cout << " set 1 " << endl;
      return 1;
    } else {
      mem[idx][taken][rem] = 0;
      return 0;
    }
  }
  if (mem[idx][taken][rem] != -1) {
    DEBUG cout << " found " << endl;
    return mem[idx][taken][rem];
  }
  mem[idx][taken][rem] = backtrack(idx + 1, taken, rem) +
                         backtrack(idx + 1, taken + 1, (rem + nums[idx]) % d);
  DEBUG cout << " returning " << mem[idx][taken][rem] << endl;
  return mem[idx][taken][rem];
}

int main() {
  int q;
  cin >> n >> q;
  int ct = 1;
  while (n | q) {
    printf("SET %d:\n", ct++);
    nums.clear();
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    for (int iq = 0; iq < q; iq++) {
      memset(mem, -1, sizeof mem);
      cin >> d >> m;
      printf("QUERY %d: %lld\n", iq + 1, backtrack(0, 0, 0));
    }
    cin >> n >> q;
  }
}
