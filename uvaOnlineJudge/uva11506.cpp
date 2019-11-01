#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
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
int flow[102][102];
int p[102];
int inf = 1e9;
vector<vi> adj;
int f;
int s = 0;
int t = 1;
void aug(int v, int mn) {
  if (v == s)
    f = mn;
  else if (p[v] != -1) {
    aug(p[v], min(mn, flow[p[v]][v]));
    flow[p[v]][v] -= f;
    flow[v][p[v]] += f;
  }
}
int main() {
  int m, w;
  cin >> m >> w;
  while (m | w) {
    memset(flow, 0, sizeof flow);
    adj.clear();
    int n = m * 2;
    adj.reserve(n);
    for (int i = 0; i < n; i++) {
      adj.push_back({});
    }
    for (int i = 0; i < m - 2; i++) {
      int mach, cost;
      cin >> mach >> cost;
      mach--;
      adj[mach].push_back(m + mach);
      adj[m + mach].push_back(mach);
      flow[mach][m + mach] = cost;
    }
    adj[0].push_back(m);
    adj[m].push_back(0);
    flow[0][m] = inf;
    adj[2 * m - 1].push_back(m - 1);
    adj[m - 1].push_back(2 * m - 1);
    flow[m - 1][2 * m - 1] = inf;

    for (int i = 0; i < w; i++) {
      int a, b, cost;
      cin >> a >> b >> cost;
      a--;
      b--;
      adj[a].push_back(b + m);
      adj[b + m].push_back(a);

      adj[a + m].push_back(b);
      adj[b].push_back(a + m);
      flow[a + m][b] = cost;
      flow[b + m][a] = cost;
    }
    s = 0;
    t = 2 * m - 1;
    int mf = 0;
    while (true) {
      memset(p, -1, sizeof p);
      bitset<102> seen;
      queue<int> q;
      q.push(s);
      seen[s] = true;
      f = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
          break;
        for (auto v : adj[u]) {
          if (seen[v])
            continue;
          if (flow[u][v] > 0) {
            seen[v] = true;
            q.push(v);
            p[v] = u;
          }
        }
      }
      aug(t, inf);
      if (f == 0)
        break;
      mf += f;
    }
    cout << mf << endl;
    cin >> m >> w;
  }
}
