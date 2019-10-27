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


// easier solution is to dfs to find a topo ordering
// then dfs again following topo ordering, count connected components
class UnionFind {
private:
  vi p, rank;
  vi sz;
  int ct;

public:
  UnionFind(int N) {
    ct = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) {
      sz.push_back(1);
      p[i] = i;
    }
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int getSize(int i) { return sz[findSet(i)]; }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      // if from different set
      ct--;
      int x = findSet(i), y = findSet(j);
      sz[x] += sz[y];
      sz[y] = sz[x];
      if (rank[x] > rank[y])
        p[y] = x;
      // rank keeps the tree short
      else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
};

UnionFind *uf;
vector<vi> adj, badj;
vi low, num, visited;
vi s;
vi sccs;
int dfsnum;

void dfs(int u) {
  num[u] = low[u] = dfsnum++;
  s.push_back(u);
  visited[u] = 1;
  for (auto v : adj[u]) {
    if (num[v] == -1)
      dfs(v);
    if (visited[v])
      low[u] = min(low[v], low[u]);
  }
  if (num[u] == low[u]) {
    while (true) {
      int bk = s.back();
      s.pop_back();
      uf->unionSet(bk, u);
      visited[bk] = 0;
      if (u == bk)
        break;
    }
    sccs.push_back(u);
  }
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int n, m;
    cin >> n >> m;

    adj.clear();
    badj.clear();
    s.clear();
    sccs.clear();
    low.assign(n, 0);
    num.assign(n, -1);
    visited.assign(n, 0);
    badj.reserve(n);
    adj.reserve(n);
    for (int i = 0; i < n; i++) {
      adj.push_back({});
      badj.push_back({});
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      adj[a - 1].push_back(b - 1);
      badj[b - 1].push_back(a - 1);
    }
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    uf = new UnionFind(n);
    dfsnum = 0;
    for (int i = 0; i < n; i++) {
      if (num[i] == -1)
        dfs(i);
    }
    int out = 0;
    bool *dont_knock = new bool[n]();
    for (int i = 0; i < n; i++) {
      auto &row = badj[i];
      for (auto &elem : row) {
        elem = uf->findSet(elem);
      }
      sort(row.begin(), row.end());
      auto it = unique(row.begin(), row.end());
      row.resize(distance(row.begin(), it));
      if (row.size() > 1 || (row.size() == 1 && row[0] != uf->findSet(i))) {
        dont_knock[uf->findSet(i)] = true;
      }
    }
    for (auto i : sccs) {
      out += !dont_knock[i];
    }
    cout << out << endl;
    delete[] dont_knock;

    delete uf;
  }
}
