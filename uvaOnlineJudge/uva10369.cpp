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

public:
  int ct;
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

typedef pair<long, ii> lii;
int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int s, p;
    cin >> s >> p;
    vii pts;
    pts.reserve(p);
    UnionFind uf(p);
    for (int i = 0; i < p; i++) {
      int x, y;
      cin >> x >> y;
      pts.push_back(ii(x, y));
    }
    vector<lii> edges;
    edges.reserve(p * p);
    for (int i = 0; i < p; i++) {
      for (int j = i + 1; j < p; j++) {
        long dx = abs(pts[i].first - pts[j].first);
        long dy = abs(pts[i].second - pts[j].second);
        dx *= dx;
        dy *= dy;
        edges.push_back(lii(dx + dy, ii(i, j)));
      }
    }
    sort(edges.begin(), edges.end());
    double out = 0;
    for (auto edge : edges) {
      if (uf.ct == s)
        break;
      int a = edge.second.first;
      int b = edge.second.second;
      if (uf.isSameSet(a, b))
        continue;
      uf.unionSet(a, b);
      out = sqrt(edge.first);
    }
    printf("%.2lf\n", out);
  }
}
