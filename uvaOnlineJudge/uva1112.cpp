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

int dist[102];
int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int inf = 1e8;
    if (ic)
      cout << endl;
    int n, e, t;
    cin >> n >> e >> t;
    e--;
    inf = max(inf, t + 2);
    fill_n(dist, n, inf);
    vector<vii> adj;
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      adj[b].push_back(ii(a, c));
    }
    priority_queue<ii, vii, greater<ii>> q;

    q.push(ii(0, e));
    dist[e] = 0;
    while (!q.empty()) {
      auto cur = q.top();
      q.pop();

      int d = cur.first;
      int u = cur.second;

      if (d > dist[u])
        continue;
      for (auto pv : adj[u]) {
        int v = pv.first;

        if (dist[u] + pv.second < dist[v]) {
          dist[v] = dist[u] + pv.second;
          DEBUG printf("set %d %d\n", v, dist[v]);
          q.push(ii(dist[v], v));
        }
      }
    }
    int out = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] <= t)
        out++;
      DEBUG printf("%d %d\n", i, dist[i]);
    }
    cout << out << endl;
  }
}
