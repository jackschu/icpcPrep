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

void printBoard(const set<ii> &board, int w = 11, int h = 7) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << (board.find(make_pair(i, j)) == board.end() ? '.' : '#');
    cout << endl;
  }
}

int transform(int line, int target) {
  return target > line ? line * 2 - target : target;
}

int main() {
  string l;
  set<ii> points;
  while (getline(cin, l) && l.size() != 0) {
    int x, y;
    sscanf(l.c_str(), "%d,%d", &x, &y);
    points.insert(make_pair(y, x));
  }

  while (getline(cin, l)) {
    int val;
    char axis;
    sscanf(l.c_str(), "fold along %c=%d", &axis, &val);
    set<ii> new_points;
    for (auto &point : points) {
      if (axis == 'y' && point.first == val)
        continue;
      if (axis == 'x' && point.second == val)
        continue;
      int x = axis == 'x' ? transform(val, point.second) : point.second;
      int y = axis == 'y' ? transform(val, point.first) : point.first;
      new_points.insert(make_pair(y, x));
    }
    points = new_points;
  }
  int w = 0;
  int h = 0;
  for (auto point : points) {
    w = max(w, point.second);
    h = max(h, point.first);
  }
  printBoard(points, w + 1, h + 1);
}
