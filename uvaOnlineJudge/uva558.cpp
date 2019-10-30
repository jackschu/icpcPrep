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
  int tc;
  cin >> tc;
  int inf = 1e9;
  for (int ic = 0; ic < tc; ic++) {
    int n, m;
    cin >> n >> m;
    vector<vii> adj;
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back(ii(b, c));
    }
    vi dist(n, inf);
    bool out = false;
    bool mod = true;
    for (int i = 0; i < n && mod; i++) {
      mod = false;
      for (int u = 0; u < n; u++) {
        for (auto pv : adj[u]) {
          if (dist[u] + pv.second < dist[pv.first]) {
            mod = true;
            dist[pv.first] = dist[u] + pv.second;
            if (i == n - 1)
              out = true;
          }
        }
      }
    }
    if (!out)
      cout << "not possible" << endl;
    else
      cout << "possible" << endl;
  }
}
