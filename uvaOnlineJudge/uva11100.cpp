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

int main() {
  int n;
  cin >> n;
  bool mfirst = true;
  while (n) {
    if (!mfirst)
      cout << endl;
    mfirst = false;
    vi nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    sort(nums.begin(), nums.end());
    int mx = 1;
    int ct = 1;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      if (x == prev) {
        ct++;
        mx = max(mx, ct);
      } else {
        ct = 1;
      }
      prev = x;
    }
    cout << mx << endl;
    vector<vi> outs;
    outs.reserve(mx);
    for (int i = 0; i < mx; i++) {
      outs.push_back({});
    }
    for (int i = 0; i < n; i++) {
      outs[i % mx].push_back(nums[i]);
    }
    for (auto &row : outs) {
      bool first = true;
      for (auto elem : row) {
        if (!first)
          cout << " ";
        first = false;
        cout << elem;
      }
      cout << endl;
    }
    cin >> n;
  }
}
