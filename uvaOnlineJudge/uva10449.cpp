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
typedef long long ll;

int main() {
  int n;
  int inf = 1e9;
  int ic = 0;
  while (cin >> n) {
    printf("Set #%d\n", ++ic);
    vi busy;
    busy.reserve(n);
    if (n == 0) {
      int r, q;
      cin >> r >> q;
      continue;
    }
    copy_n(istream_iterator<int>(cin), n, back_inserter(busy));
    int r;
    cin >> r;
    vector<vii> adj;
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < r; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      int c = busy[b] - busy[a];
      c = c * c * c;
      adj[a].push_back(ii(b, c));
      DEBUG printf("a %d b %d c %d\n", a, b, c);
    }
    vi dist(n, inf);
    dist[0] = 0;
    bool mod = true;
    vector<bool> fail(n, false);

    // this is bellman-ford
    // SPFA with a seen count for neg cycle check maybe more intuitive
    for (int i = 0; i < 2 * n && mod; i++) {
      mod = false;
      for (int u = 0; u < n; u++) {
        for (auto pv : adj[u]) {
          if (pv.second + dist[u] < dist[pv.first] && dist[u] != inf) {
            mod = true;
            dist[pv.first] = pv.second + dist[u];
            if (i >= n - 1) {
              fail[pv.first] = true;
            }
          }
        }
      }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      x--;
      if (fail[x] || dist[x] < 3 || dist[x] == inf)
        cout << "?" << endl;
      else
        cout << dist[x] << endl;
    }
  }
}
