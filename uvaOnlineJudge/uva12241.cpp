#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
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

vi scanto(int start, vi cur, int targ) {
  int i = start;
  while (i++ != targ) {
    int x = i;
    while (x) {
      int d = x % 10;
      x /= 10;
      cur[d]++;
    }
  }
  return cur;
}

int main() {
  vector<pair<int, vi>> digs;
  int top = 10000;
  int bigg = 1e8 + 2;
  digs.reserve(top);
  for (int i = 0; i < top; i++) {
    digs.push_back(pair<int, vi>(i, {}));
    digs[i].second.assign(10, 0);
    DEBUG cout << i << endl;
  }

  for (int i = 1; i < top; i++) {
    digs[i].second = digs[i - 1].second;
    int x = i;
    while (x) {
      int d = x % 10;
      x /= 10;
      digs[i].second[d]++;
    }
  }
  int idx = 9999;
  for (int i = 20000 - 1; i < bigg; i += 10000) {
    int front = i / 10000;
    vi cur = digs[idx].second;
    while (front) {
      int d = front % 10;
      front /= 10;
      cur[d] += 10000;
    }
    for (int i = 0; i < 10; i++)
      cur[i] += 4000;
    digs.push_back(pair<int, vi>(i, cur));
    idx++;
  }

  DEBUG cout << "inited " << endl;
  int a, b;
  cin >> a >> b;
  while (a | b) {
    a--;
    auto fa = lower_bound(digs.begin(), digs.end(), pair<int, vi>(a, {}));
    int an = distance(digs.begin(), fa);
    if (digs[an].first != a)
      an--;

    vi low = scanto(digs[an].first, digs[an].second, a);

    auto fb = lower_bound(digs.begin(), digs.end(), pair<int, vi>(b, {}));
    int bn = distance(digs.begin(), fb);
    if (digs[bn].first != b)
      bn--;
    vi high = scanto(digs[bn].first, digs[bn].second, b);
    for (int i = 0; i < 10; i++) {
      if (i != 0)
        cout << " ";
      cout << high[i] - low[i];
    }
    cout << endl;
    cin >> a >> b;
  }
}
