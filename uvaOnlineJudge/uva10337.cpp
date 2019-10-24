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
vector<vi> data;
int lvl;
int mem[10][1003];
int inf = (int)1e7;
int backtrack(int h, int dist) { // cost to finish dist at hight h
  if (h < 0 || h > 9)
    return inf;
  if (dist == -1)
    return h == 0 ? 0 : inf;
  if (mem[h][dist] != -1)
    return mem[h][dist];
  int out = backtrack(h, dist - 1) - data[h][dist] + 30;
  if (h > 0) {
    int optneg = backtrack(h - 1, dist - 1) - data[h - 1][dist] + 60;
    out = min(out, optneg);
  }
  if (h < 9) {
    int optpos = backtrack(h + 1, dist - 1) - data[h + 1][dist] + 20;
    out = min(out, optpos);
  }
  return mem[h][dist] = out;
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int x;
    cin >> x;
    lvl = x / 100;
    data.clear();
    data.reserve(10);
    for (int i = 0; i < 10; i++) {
      data.push_back({});
      data[i].reserve(lvl);
    }

    memset(mem, -1, sizeof mem);
    for (int i = 9; i >= 0; i--) {
      copy_n(istream_iterator<int>(cin), lvl, back_inserter(data[i]));
    }
    cout << backtrack(0, lvl - 1) << endl << endl;
  }
}
