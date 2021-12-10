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

void printBoard(int board[104][104], int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << (board[i][j] == -1 ? 'X' : char(board[i][j] + '0'));
    cout << endl;
  }
}

int visitAndMeasureBasin(int board[104][104], ii target, int h, int w) {
  int basin_size = 0;
  queue<ii> to_visit;

  to_visit.push(target);
  while (!to_visit.empty()) {
    auto cur = to_visit.front();
    to_visit.pop();
    if (board[cur.first][cur.second] == 9)
      continue;

    basin_size++;
    board[cur.first][cur.second] = 9;
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int cur_x = cur.second + dx[i];
      int cur_y = cur.first + dy[i];
      if (cur_x < 0 || cur_x >= w)
        continue;
      if (cur_y < 0 || cur_y >= h)
        continue;
      if (board[cur_y][cur_x] == 9)
        continue;
      to_visit.push(make_pair(cur_y, cur_x));
    }
  }
  return basin_size;
}

int main() {
  string l;
  int board[104][104];
  vi basin_sizes;
  vector<ii> initial_visit_list;
  memset(board, 0, sizeof board);
  int h = 0;
  while (getline(cin, l)) {
    for (int i = 0; i < l.size(); i++) {
      if (l[i] != '9')
        initial_visit_list.push_back(make_pair(h, i));
      board[h][i] = l[i] - '0';
    }
    h++;
  }
  int w = l.size();

  for (auto initial_visit_item : initial_visit_list) {
    if (board[initial_visit_item.first][initial_visit_item.second] == 9)
      continue;
    int basin_size = visitAndMeasureBasin(board, initial_visit_item, h, w);
    basin_sizes.push_back(basin_size);
  }

  sort(basin_sizes.begin(), basin_sizes.end());
  int out = 1;
  for (int i = 0; i < 3; i++)
    out *= basin_sizes[basin_sizes.size() - 1 - i];
  cout << out << endl;
}
