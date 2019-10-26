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
int num[100], low[100], parent[100];
bool critical[100];
int dfsct, rootct;
int rootidx, n;

void dfs(int u) {
  low[u] = num[u] = dfsct++;
  for (auto v : adj[u]) {
    if (num[v] == -1) {
      if (u == rootidx)
        rootct++;
      dfs(v);
      if (low[v] >= num[u])
        critical[u] = true;
      low[u] = min(low[u], low[v]);
    } else if (v != parent[u]) {
      low[u] = min(low[u], num[v]);
    }
  }
}
int main() {
  cin >> n;
  while (n) {
    int a;
    adj.clear();
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    cin >> a;
    while (a) {

      string l;
      getline(cin, l);
      stringstream ss(l);
      int b;
      while (ss >> b) {
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
      }
      cin >> a;
    }
    memset(critical, 0, sizeof critical);
    memset(num, -1, sizeof num);
    memset(low, 1000, sizeof low);
    memset(parent, -1, sizeof parent);
    for (int i = 0; i < n; i++) {
      if (num[i] != -1)
        continue;
      dfsct = 0;
      rootct = 0;
      rootidx = i;
      dfs(i);
      DEBUG printf("root %d rootct %d\n", i, rootct);
      critical[i] = rootct > 1;
    }
    int out = 0;
    for (int i = 0; i < n; i++) {
      if (critical[i]) {
        DEBUG cout << i << endl;
        out++;
      }
    }
    cout << out << endl;

    cin >> n;
  }
}
