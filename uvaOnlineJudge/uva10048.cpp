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
vector<vii> adj;
int seen[100];

vii path, ans;
bool stop;
void dfs(int u, int targ) {
  DEBUG cout << "dfs " << u << endl;
  if (seen[u])
    return;
  seen[u] = 1;
  for (auto v : adj[u]) {
    if (stop)
      return;
    if (v.first == targ) {
      path.push_back(v);
      ans = path;
      stop = true;
    } else {
      path.push_back(v);
      dfs(v.first, targ);
      path.pop_back();
    }
  }
}
int main() {
  int ic = 1;
  int c, s, q;
  cin >> c >> s >> q;
  while (c | s | q) {
    if (ic != 1)
      cout << endl;
    printf("Case #%d\n", ic++);

    UnionFind uf(c);
    vector<pair<int, ii>> edges;
    edges.reserve(s);
    adj.clear();
    adj.reserve(c);
    for (int i = 0; i < c; i++)
      adj.push_back({});
    for (int i = 0; i < s; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      a--;
      b--;
      edges.push_back(pair<int, ii>(w, ii(a, b)));
    }
    sort(edges.begin(), edges.end());

    for (auto &edge : edges) {
      int a = edge.second.first;
      int b = edge.second.second;
      if (uf.isSameSet(a, b))
        continue;
      uf.unionSet(a, b);
      adj[a].push_back(ii(b, edge.first));
      adj[b].push_back(ii(a, edge.first));
    }
    for (int iq = 0; iq < q; iq++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      if (!uf.isSameSet(a, b)) {
        cout << "no path" << endl;
        continue;
      }
      path.clear();
      stop = false;
      ans.clear();
      memset(seen, 0, sizeof seen);
      dfs(a, b);
      int out = -1;
      for (auto elem : ans)
        out = max(out, elem.second);
      cout << out << endl;
    }
    cin >> c >> s >> q;
  }
}
