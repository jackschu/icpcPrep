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
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (true)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi offs = {1, 15 + 64, 16 + 2, 6, 64 + 12, 32 + 4, 32, 15, 0, 4};
vi ons;

int main() {
  for (auto elem : offs) {
    ons.push_back(127 ^ elem);
  }
  int n;
  cin >> n;
  while (n) {
    vi nums;
    vi actual_offs;
    int seen_on[7];
    fill_n(seen_on, 7, -1);
    for (int i = 0; i < n; i++) {
      int num = 0;
      for (int j = 0; j < 7; j++) {
        char c;
        cin >> c;
        if (c == 'Y') {
          num |= 1 << (6 - j);
          seen_on[6 - j] = i;
        }
      }
      nums.push_back(num);
    }

    for (int i = 0; i < n; i++) {
      int off = 0;
      for (int j = 0; j < 7; j++) {
        if ((nums[i] & 1 << j) || seen_on[j] < i)
          continue;
        off |= 1 << j;
      }
      actual_offs.push_back(off);
    }

    vector<set<int>> orders;
    for (int i = 0; i < n; i++) {
      orders.push_back({});
      for (int j = 0; j < 10; j++) {
        if ((offs[j] & nums[i]) || (ons[j] & actual_offs[i]))
          continue;
        orders[i].insert(j);
      }
    }
    bool win = false;
    for (auto elem : orders[0]) {
      win = true;
      for (int i = 1; i < n && win; i++) {
        win &= orders[i].find(elem - i) != orders[i].end();
      }
      if (win)
        break;
    }

    cout << (win ? "MATCH" : "MISMATCH") << endl;
    cin >> n;
  }
}
