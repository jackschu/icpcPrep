#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
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

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int n;
    cin >> n;
    vector<vi> input;
    input.reserve(2 * n);
    for (int i = 0; i < n; i++) {
      input.push_back({});
      input[i].reserve(2 * n);
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        input[i].push_back(x);
      }
      for (int j = n; j < 2 * n; j++) {
        input[i].push_back(input[i][j - n]);
      }
    }

    for (int j = n; j < 2 * n; j++) {
      input.push_back(input[j - n]);
    }
    vector<vector<long>> sums;
    sums.reserve(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      sums.push_back({});
      sums[i].reserve(2 * n);
      for (int j = 0; j < 2 * n; j++) {
        long x = input[i][j];
        if (i > 0)
          x += sums[i - 1][j];
        if (j > 0)
          x += sums[i][j - 1];
        if (i > 0 && j > 0)
          x -= sums[i - 1][j - 1];
        sums[i].push_back(x);
      }
    }
    long best = sums[0][0];
    for (int i1 = n; i1 < 2 * n; i1++) {
      for (int j1 = n; j1 < 2 * n; j1++) {
        for (int id = 0; id < n; id++) {
          for (int jd = 0; jd < n; jd++) {
            long cur = sums[i1][j1];
            DEBUG printf("%d %d %d %d\n", i1, id, j1, jd);
            cur -= sums[i1 - id - 1][j1];
            cur -= sums[i1][j1 - jd - 1];
            cur += sums[i1 - id - 1][j1 - jd - 1];
            best = max(cur, best);
          }
        }
      }
    }
    cout << best << endl;
  }
}
