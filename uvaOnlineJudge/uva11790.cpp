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
    if (n == 0) {
      printf("Case %d. Increasing (0). Decreasing (0).\n", ic + 1);
      continue;
    }
    vi a, w;
    a.reserve(n);
    w.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    copy_n(istream_iterator<int>(cin), n, back_inserter(w));
    if (n == 1) {
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", ic + 1, w[0],
             w[0]);
      continue;
    }
    vi dec, inc;
    dec.reserve(n);
    inc.reserve(n);
    dec.push_back(w[0]);
    inc.push_back(w[0]);
    int out_i = w[0], out_d = w[0];
    for (int i = 1; i < n; i++) {
      int mxi = w[i];
      int mxd = w[i];
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j])
          mxi = max(inc[j] + w[i], mxi);
        else if (a[i] < a[j])
          mxd = max(dec[j] + w[i], mxd);
      }
      dec.push_back(mxd);
      inc.push_back(mxi);
      out_i = max(out_i, mxi);
      out_d = max(out_d, mxd);
    }
    for (int i = 0; i < n; i++) {
      DEBUG printf("n %d   inc %d   dec %d\n", a[i], inc[i], dec[i]);
    }
    if (out_i >= out_d) {
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", ic + 1, out_i,
             out_d);
    } else {
      printf("Case %d. Decreasing (%d). Increasing (%d).\n", ic + 1, out_d,
             out_i);
    }
  }
}
