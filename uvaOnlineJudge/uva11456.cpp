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

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int n;
    cin >> n;
    vi a;
    a.reserve(n);
    for (int in = 0; in < n; in++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    if (n < 2) {
      cout << n << endl;
      continue;
    }
    reverse(a.begin(), a.end());
    vi dec, inc;
    dec.reserve(n);
    inc.reserve(n);
    dec.push_back(1);
    inc.push_back(1);
    int out = 1;
    for (int i = 1; i < n; i++) {
      int mxi = 1;
      int mxd = 1;
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j])
          mxi = max(inc[j] + 1, mxi);
        else
          mxd = max(dec[j] + 1, mxd);
      }
      dec.push_back(mxd);
      inc.push_back(mxi);
      out = max(out, mxi + mxd - 1);
    }
    for (int i = 0; i < n; i++) {
      DEBUG printf("n %d   inc %d   dec %d\n", a[i], inc[i], dec[i]);
    }
    cout << out << endl;
  }
}
