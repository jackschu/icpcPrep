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
int *num;
void dfs(int u) {
  num[u] = 1;
  for (auto v : adj[u])
    if (num[v] == 0)
      dfs(v);
  ts.push_back(u);
}

int main() {
  int n;
  bool first = true;
  while (cin >> n) {
    if (!first)
      cout << endl;
    first = false;
    adj.clear();
    ts.clear();
    num = new int[n + 1]();
    for (int in = 0; in < n; in++) {
      adj.push_back({});
      int no;
      cin >> no;
      for (int i = 0; i < no; i++) {
        int b;
        cin >> b;
        adj[in].push_back(b);
      }
    }
    for (int i = 0; i < n; i++) {
      if (num[i])
        continue;
      dfs(i);
    }
    int sz = ts.size();
    fill_n(num, n + 1, 0);
    num[0] = 1;
    int out = 0;
    for (int i = sz - 1; i >= 0; i--) {
      int u = ts[i];
      for (auto v : adj[u]) {
        num[v] += num[u];
      }
      if (adj[u].size() == 0)
        out += num[u];
    }

    cout << out << endl;
    delete[] num;
  }
}
