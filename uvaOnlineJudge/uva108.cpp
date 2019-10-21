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
  int n;
  while (cin >> n) {
    vector<vector<long>> data;
    data.reserve(n);
    for (int i = 0; i < n; i++) {
      data.push_back({});
      data[i].reserve(n);
      for (int j = 0; j < n; j++) {
        long x;
        cin >> x;
        if (j > 0)
          x += data[i][j - 1];
        data[i].push_back(x);
      }
    }

    long best = data[0][0];
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1; i2 < n; i2++) {
        long sum = 0;
        for (int j = 0; j < n; j++) {
          long x = data[j][i2];
          if (i1 > 0)
            x -= data[j][i1 - 1];
          sum += x;
          best = max(sum, best);
          if (sum < 0)
            sum = 0;
        }
      }
    }
    cout << best << endl;
  }
}
