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

bool comp(const vi &i, const vi &j) { return i.size() > j.size(); }
vector<vi> h;
int main() {
  int n, m;
  cin >> n >> m;
  while (n | m) {
    h.clear();
    h.reserve(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
      h.push_back({});
      h[i].reserve(n + m);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        h[i - j + (m - 1)].push_back(x);
      }
    }
    sort(h.begin(), h.end(), comp);
    int q;
    cin >> q;
    for (int ic = 0; ic < q; ic++) {
      int l, u;
      scanf("%d %d", &l, &u);
      int mx = 0;
      for (int i = 0; i < m + n - 1; i++) {
        auto &row = h[i];
        if (row.size() < mx)
          continue;
        auto st = row.begin(), sp = row.end();
        int curl = lower_bound(st, sp, l) - st;
        int curh = upper_bound(st, sp, u, less<int>()) - st;
        mx = max(mx, curh - curl);
      }
      printf("%d\n", mx);
    }
    printf("-\n");
    cin >> n >> m;
  }
}
