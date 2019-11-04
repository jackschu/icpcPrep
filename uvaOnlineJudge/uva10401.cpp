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
vector<vi> adj;
vi ts;
bitset<225> seen;
bool board[15][15];
void dfs(int u) {
  seen[u] = true;
  for (auto v : adj[u])
    if (!seen[v])
      dfs(v);
  ts.push_back(u);
}
int main() {
  string l;
  while (cin >> l) {
    memset(board, true, sizeof board);
    int n = l.size();
    for (int i = 0; i < n; i++) {
      if (l[i] == '?')
        continue;
      for (int j = 0; j < n; j++) {
        board[i][j] = false;
      }
      int c;
      if (isdigit(l[i]))
        c = l[i] - '1';
      else
        c = l[i] - 'A' + 10 - 1;
      if (i > 0) {
        board[i - 1][c] = false;
        if (c < n - 1)
          board[i - 1][c + 1] = false;
        if (c > 0)
          board[i - 1][c - 1] = false;
      }
      board[i][c] = true;
    }
    
    adj.clear();
    adj.reserve(n * n);
    ts.clear();
    ts.reserve(n * n);
    for (int i = 0; i < n * n; i++)
      adj.push_back({});
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n; j++) {
        int a = i * n + j;
        if (!board[i][j])
          continue;
        for (int k = 0; k < n; k++) {
          if (abs(j - k) < 2)
            continue;
          if (!board[i + 1][k])
            continue;
          int b = (i + 1) * n + k;
          adj[a].push_back(b);
        }
      }
    }
    seen.reset();
    for (int i = 0; i < n * n; i++)
      if (!seen[i])
        dfs(i);
    ll *ct = new ll[n * n]();
    for (int i = 0; i < n; i++)
      ct[i] = 1;
    int sz = ts.size();
    for (int i = sz - 1; i >= 0; i--) {
      int u = ts[i];
      for (auto v : adj[u]) {
        ct[v] += ct[u];
      }
    }

    ll out = 0;
    for (int i = 0; i < n; i++)
      out += ct[n * n - n + i];
    cout << out << endl;
    delete[] ct;
  }
}
