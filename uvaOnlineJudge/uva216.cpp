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
vii comps;
double dist[10][10];
double mem[10][515];
ii ans[10][515];
ii start;
int n;
void print(int prev, ii next) {
  if (next.first == -1)
    return;
  int nexti = next.first;
  if (prev != -1) {
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
           comps[prev].first, comps[prev].second, comps[nexti].first,
           comps[nexti].second, dist[prev][nexti] + 16);
  }

  print(next.first, ans[next.first][next.second]);
}
double backtrack(int last, int used) {
  DEBUG printf("%d %d\n", last, used);
  if (last != -1) {
    if (mem[last][used] != -1) {
      return mem[last][used];
    }
    if (used == (1 << n) - 1) {
      return mem[last][used] = 0;
    }
  }
  double best = -1;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (used & 1 << i)
      continue;
    double cur = (last == -1 ? 0 : dist[last][i]) + backtrack(i, used | 1 << i);
    if (best == -1 || cur < best) {
      best = cur;
      idx = i;
    }
  }
  if (last == -1)
    start = ii(idx, used | 1 << idx);
  else
    ans[last][used] = ii(idx, used | 1 << idx);
  return last == -1 ? best : (mem[last][used] = best);
}
int main() {
  cin >> n;
  int ic = 0;
  while (n != 0) {
    ic++;
    cout << "**********************************************************"
         << endl;
    printf("Network #%d\n", ic);
    comps.clear();
    comps.reserve(n);
    
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      comps.push_back(ii(x, y));
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ii a = comps[i], b = comps[j];
        dist[i][j] =
            hypot(double(a.first - b.first), double(a.second - b.second));
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 515; j++) {
        mem[i][j] = -1;
        ans[i][j] = ii(-1, -1);
      }
    }

    double out = (n - 1) * 16 + backtrack(-1, 0);
    print(-1, start);
    printf("Number of feet of cable required is %.2lf.\n", out);
    cin >> n;
  }
}
