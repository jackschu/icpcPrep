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
int flow[2000][2000];
int p[2000];
char board[30][30];
vector<vi> adj;
int f;
int s = 0;
int t = 1;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
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
  int r;
  while (cin >> r) {
    adj.clear();
    memset(flow, 0, sizeof flow);
    int c, P;
    cin >> c >> P;
    int inf = 1e5;
    int n = 2 + r * c + r * c;
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        char x;
        cin >> x;
        board[i][j] = x;
        if (x == '~')
          continue;
        int v1 = i * c + j + 2;
        int v2 = r * c + c * i + j + 2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        if (x == '.' || x == '*') {
          flow[v1][v2] = 1;
        } else {
          flow[v1][v2] = inf;
        }
        if (x == '*') {
          adj[0].push_back(v1);
          adj[v1].push_back(0);
          flow[0][v1] = 1;
        }
        if (x == '#') {
          adj[1].push_back(v2);
          adj[v2].push_back(1);
          flow[v2][1] = P;
        }
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int v1 = c * i + j + 2 + r * c;
        if (board[i][j] == '~')
          continue;
        for (int d = 0; d < 4; d++) {
          int ni = i + dy[d];
          int nj = j + dx[d];
          if (ni < 0 || ni >= r || nj < 0 || nj >= c)
            continue;
          if (board[ni][nj] == '~')
            continue;
          int v2 = c * ni + nj + 2;
          adj[v1].push_back(v2);
          adj[v2].push_back(v1);
          flow[v1][v2] = inf;
        }
      }
    }

    int mf = 0;
    while (true) {
      memset(p, -1, sizeof p);
      queue<int> q;
      f = 0;
      q.push(s);
      bitset<2000> seen;
      seen[s] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) {
          break;
        }
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
      aug(t, 2 * inf);

      if (f == 0)
        break;
      mf += f;
    }
    cout << mf << endl;
  }
}
