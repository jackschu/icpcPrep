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

UnionFind *uf;

int main() {
  int tc;
  cin >> tc;

  for (int ic = 0; ic < tc; ic++) {
    int n;
    long r;
    cin >> n >> r;
    vii pts;
    r *= r;
    pts.reserve(n);
    vector<pair<long, ii>> edges;
    edges.reserve(n * n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      pts.push_back(ii(x, y));
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long xd = abs(pts[i].first - pts[j].first);
        long yd = abs(pts[i].second - pts[j].second);
        xd *= xd;
        yd *= yd;
        edges.push_back(pair<long, ii>(xd + yd, ii(i, j)));
      }
    }
    UnionFind uf(n);
    int stct = 1;
    double rr = 0;
    double road = 0;
    sort(edges.begin(), edges.end());
    for (auto &edge : edges) {
      if (uf.isSameSet(edge.second.first, edge.second.second))
        continue;
      long dist = edge.first;
      uf.unionSet(edge.second.first, edge.second.second);
      if (dist > r) {
        stct++;
        rr += sqrt(dist);
      } else {
        road += sqrt(dist);
      }
    }
    printf("Case #%d: %d %d %d\n", ic + 1, stct, (int)round(road),
           (int)round(rr));
  }
}
