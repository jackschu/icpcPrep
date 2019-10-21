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
    if (ic != 0)
      cout << endl;
    vector<vector<vector<long>>> slices;

    int a, b, c;
    cin >> a >> b >> c;
    for (int k = 0; k < a; k++) {
      vector<vector<long>> data;
      data.reserve(b);
      for (int i = 0; i < b; i++) {
        data.push_back({});
        data[i].reserve(c);
        for (int j = 0; j < c; j++) {
          long x;
          cin >> x;
          if (i > 0)
            x += data[i - 1][j];
          if (j > 0)
            x += data[i][j - 1];
          if (i > 0 && j > 0)
            x -= data[i - 1][j - 1];
          data[i].push_back(x);
        }
      }
      for (auto row : data) {
        for (auto elem : row) {
          DEBUG cout << elem << " ";
        }
        DEBUG cout << endl;
      }
      slices.push_back(data);
    }
    long best = slices[0][0][0];
    for (int i1 = 0; i1 < b; i1++) {
      for (int j1 = 0; j1 < c; j1++) {
        for (int i2 = i1; i2 < b; i2++) {
          for (int j2 = j1; j2 < c; j2++) {
            long sum = 0;
            for (int k = 0; k < a; k++) {
              auto &slice = slices[k];
              long x = slice[i2][j2];
              if (i1 > 0)
                x -= slice[i1 - 1][j2];
              if (j1 > 0)
                x -= slice[i2][j1 - 1];
              if (j1 > 0 && i1 > 0)
                x += slice[i1 - 1][j1 - 1];
              sum += x;
              best = max(best, sum);
              if (sum < 0)
                sum = 0;
            }
          }
        }
      }
    }
    cout << best << endl;
  }
}
