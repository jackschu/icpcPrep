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
typedef pair<int, ii> iii;

int main() {
  int inf = 1e9;
  map<char, int> col;
  col['R'] = 0;
  col['O'] = 1;
  col['Y'] = 2;
  col['G'] = 3;
  col['B'] = 4;
  col['I'] = 5;
  col['V'] = 6;
  int n_set = 1 << 7;
  int n, m;
  cin >> n >> m;
  vector<vector<vector<iii>>> adj;
  vector<vector<int>> dist;
  dist.reserve(n_set);
  adj.reserve(n_set);
  for (int i = 0; i < n_set; i++) {
    dist.push_back({});
    adj.push_back({});
    adj[i].reserve(n);
    dist[i].assign(n, inf);
  }
  DEBUG cout << "empty" << endl;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    char color_c;
    cin >> a >> b >> c >> color_c;
    int cmask = 1 << col[color_c];
    a--;
    b--;
    for (int j = 0; j < n_set; j++) {

      DEBUG printf("%d %d %d %d\n", j, a, b, j|cmask);

      adj[j][a].push_back(iii(c, ii(j | cmask,b)));
      adj[j][b].push_back(iii(c, ii(j | cmask,a)));
    }
  }
  DEBUG cout << "inited " << endl;
  priority_queue<iii, vector<iii>, greater<iii>> q;
  q.push(iii(0, ii(0, 0)));
  dist[0][0] = 0;
  while (!q.empty()) {
    auto cur = q.top();
    q.pop();

    int d = cur.first;
    int cs = cur.second.first;
    int loc = cur.second.second;
    DEBUG printf("cs %d cur %d\n", cs, loc);
    if (cs == n_set - 1 && loc == 0) {
      cout << d << endl;
      break;
    }
    if (d > dist[cs][loc])
      continue;
    for (auto &pv : adj[cs][loc]) {
      int csv = pv.second.first;
      int locv = pv.second.second;
      if (dist[cs][loc] + pv.first < dist[csv][locv]) {
        dist[csv][locv] = dist[cs][loc] + pv.first;
        q.push(iii(dist[csv][locv], pv.second));
      }
    }
  }
}
