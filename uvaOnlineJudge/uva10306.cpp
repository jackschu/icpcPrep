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

vi x, y;
int m;
int inf = 1e7;
int s;
int mem[42][302][302];
int cc(int idx, int xspend, int yspend) {
  int curspend = xspend * xspend + yspend * yspend;
  DEBUG printf("%d %d %d %d\n", idx, xspend, yspend, curspend);
  if (idx >= m || curspend > s) {
    return inf;
  }
  if (s == curspend)
    return 0;
  if (mem[idx][xspend][yspend] != -1) {
    return mem[idx][xspend][yspend];
  }
  int c1;
  if (y[idx] | x[idx]) {
    int nxspd = xspend + x[idx];
    int nyspd = yspend + y[idx];
    c1 = cc(idx, nxspd, nyspd) + 1;
  } else {
    c1 = inf;
  }
  int c2 = cc(idx + 1, xspend, yspend);

  return mem[idx][xspend][yspend] = min(c1, c2);
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    x.clear();
    y.clear();
    cin >> m >> s;
    s *= s;
    for (int i = 0; i < m; i++) {
      int x1, y1;
      cin >> x1 >> y1;
      x.push_back(x1);
      y.push_back(y1);
    }
    memset(mem, -1, sizeof mem);
    int out = cc(0, 0, 0);
    if (out == inf) {
      cout << "not possible" << endl;
    } else {
      cout << out << endl;
    }
  }
}
