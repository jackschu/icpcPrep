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
int n;
vi num, low, parent;
vii crits;
int dfsnum;

void dfs(int u) {
  low[u] = num[u] = dfsnum++;
  for (auto v : adj[u]) {
    if (num[v] == -1) {
      parent[v] = u;
      dfs(v);
      if (low[v] > num[u]) {
        if (v < u)
          crits.push_back(ii(v, u));
        else
          crits.push_back(ii(u, v));
      }
      low[u] = min(low[u], low[v]);
    } else if (parent[u] != v) {
      low[u] = min(low[u], num[v]);
    }
  }
}

int main() {
  while (cin >> n) {
    crits.clear();
    num.clear();
    low.clear();
    parent.clear();
    adj.clear();
    adj.reserve(n);
    num.assign(n, -1);
    parent.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      string s;
      cin >> s;
      int len = s.size();
      s = s.substr(1, len - 2);
      int m = stoi(s);
      for (int j = 0; j < m; j++) {
        int b;
        cin >> b;
        adj[a].push_back(b);
      }
    }
    dfsnum = 0;
    for (int i = 0; i < n; i++) {
      if (num[i] == -1) {
        dfs(i);
      }
    }
    sort(crits.begin(), crits.end());
    printf("%d critical links\n", (int)crits.size());
    for (auto elem : crits) {
      printf("%d - %d\n", elem.first, elem.second);
    }
    cout << endl;
  }
}
