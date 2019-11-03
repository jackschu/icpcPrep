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

vector<vii> adj;
vi ts;
bitset<52> visited;
void dfs(int u) {
  visited[u] = true;
  for (auto pv : adj[u]) {
    if (visited[pv.first])
      continue;
    dfs(pv.first);
  }
  ts.push_back(u);
}

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  string empty;

  getline(cin, empty);
  for (int ic = 0; ic < tc; ic++) {
    
    if (ic != 0)
      cout << endl;
    adj.clear();
    adj.reserve(52);
    for (int i = 0; i < 52; i++)
      adj.push_back({});
    string l;
    visited.set();
    while (getline(cin, l)) {
      if (l.size() < 2)
        break;
      stringstream ss(l);
      char bc;
      ss >> bc;
      int cost;
      ss >> cost;
      int bi = bc - 'A';
      visited[bi] = false;
      int bo = bi + 26;
      visited[bo] = false;
      adj[bi].push_back(ii(bo, cost));
      char ac;
      while (ss >> ac) {
        int ao = ac - 'A' + 26;
        visited[ao] = false;
        adj[ao].push_back(ii(bi, 0));
      }
    }
    ts.clear();
    for (int i = 0; i < 52; i++) {
      if (visited[i])
        continue;
      dfs(i);
    }
    reverse(ts.begin(), ts.end());
    int costs[52];
    int out = 0;
    memset(costs, 0, sizeof costs);
    for (auto u : ts) {
      for (auto pv : adj[u]) {
        costs[pv.first] = max(costs[pv.first], costs[u] + pv.second);
        out = max(out, costs[pv.first]);
      }
    }
    cout << out << endl;
  }
}
