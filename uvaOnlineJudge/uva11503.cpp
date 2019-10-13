#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

/**
 * Data structure from competitive programming 3
 */
class UnionFind {
private:
  vi p, rank;
  vi sz;

public:
  UnionFind(int N) {
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

void run_case() {
  int n;
  cin >> n;
  map<string, int> mp;
  vii pairs;
  pairs.reserve(n);
  int ct = 0;
  for (int i = 0; i < n; i++) {
    ct = mp.size();
    string a, b;
    cin >> a >> b;
    int x, y;
    auto found = mp.find(a);
    if (found == mp.end()) {
      mp[a] = ct;
      x = ct;
    } else {
      x = found->second;
    }
    ct = mp.size();
    found = mp.find(b);
    if (found == mp.end()) {
      mp[b] = ct;
      y = ct;
    } else {
      y = found->second;
    }
    pairs.push_back(ii(x,y));
  }
  int f_ct = mp.size();
  UnionFind uf(f_ct);
  for(auto elem: pairs){
    DEBUG cout << elem.first << " , " << elem.second << endl;
    uf.unionSet(elem.first, elem.second);
    cout << uf.getSize(elem.first)<<endl;
  }
}
int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    run_case();
  }
}
