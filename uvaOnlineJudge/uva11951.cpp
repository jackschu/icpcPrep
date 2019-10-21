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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long>> data;
    data.reserve(n);
    for (int i = 0; i < n; i++) {
      data.push_back({});
      data[i].reserve(m);
      for (int j = 0; j < m; j++) {
        long x;
        cin >> x;
        if (i > 0)
          x += data[i - 1][j];
        if (j > 0)
          x += data[i][j - 1];
        if (i > 0 && j > 0)
          x -= data[i - 1][j - 1];
        data[i][j] = x;
      }
    }
    int bestarea = 0;
    long bestcost = 1e10;
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1; i2 < n; i2++) {
        for (int j1 = 0; j1 < m; j1++) {
          for (int j2 = j1; j2 < m; j2++) {
            long cost = data[i2][j2];
            if (i1 > 0)
              cost -= data[i1 - 1][j2];
            if (j1 > 0)
              cost -= data[i2][j1 - 1];
            if (i1 > 0 && j1 > 0)
              cost += data[i1 - 1][j1 - 1];
            if (cost > k)
              continue;
            int area = (i2 - i1 + 1) * (j2 - j1 + 1);
            if (area > bestarea || (area == bestarea && bestcost > cost)) {
              bestarea = area;
              bestcost = cost;
            }
          }
        }
      }
    }
    if (bestarea == 0)
      bestcost = 0;
    printf("Case #%d: %d %ld\n", ic + 1, bestarea, bestcost);
  }
}
