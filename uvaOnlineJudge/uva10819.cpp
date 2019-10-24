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

int n;
int m;
ii mem[102][12002];
vi w, v;

ii backtrack(int id, int rem) {
  if (id >= n || (rem <= 0))
    return ii(0, 0);
  if (mem[id][rem] != ii(-1, -1))
    return mem[id][rem];
  if (rem - w[id] < 0) {
    return mem[id][rem] = backtrack(id + 1, rem);
  }
  ii opt = backtrack(id + 1, rem - w[id]);
  opt.first += v[id];
  opt.second += w[id];
  int spent = m + 200 - rem + opt.second;
  if (spent <= 2000 && spent > m) {
    return mem[id][rem] = backtrack(id + 1, rem);
  }

  return mem[id][rem] = max(backtrack(id + 1, rem), opt);
}

int main() {

  while (cin >> m >> n) {
    w.clear();
    v.clear();
    w.reserve(n);
    v.reserve(n);
    for (int i = 0; i < n; i++) {
      int x1, x2;
      cin >> x1 >> x2;
      w.push_back(x1);
      v.push_back(x2);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m + 201; j++)
        mem[i][j] = ii(-1, -1);
    int best = backtrack(0, m + 200).first;
    cout << best << endl;
  }
}
