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

void printBoard(vector<vi> &board) {
  for (auto row : board) {
    for (auto elem : row)
      cout << (elem == INT_MAX ? 'X' : char(elem + '0'));
    cout << endl;
  }
}

int main() {
  vector<vi> board;
  vector<vi> dists;
  string l;
  int h = 0, w;
  while (getline(cin, l)) {
    w = l.size();
    vi row;
    h++;
    vi empty_dists(w, INT_MAX);
    vector<bool> empty_visits(w, 0);
    for (auto one_char : l)
      row.push_back(one_char - '0');

    dists.push_back(empty_dists);
    board.push_back(row);
  }

  // implemented dijkstra's in part a before realizing that 
  // you can only move in two dirs :/
  priority_queue<pair<int, ii>> to_visit;
  to_visit.push(make_pair(0, make_pair(0, 0)));
  dists[0][0] = 0;
  while (!to_visit.empty()) {
    auto visiting = to_visit.top();
    to_visit.pop();
    int y = visiting.second.first;
    int x = visiting.second.second;
    DEBUG printf("%d,%d, %d \n", y, x, visiting.first);
    DEBUG printBoard(dists);

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    for (int i = 0; i < dx.size(); i++) {
      int new_y = y + dy[i];
      int new_x = x + dx[i];
      if (min(new_y, new_x) < 0 || new_y >= h || new_x >= w)
        continue;
      int new_dist = board[new_y][new_x] + dists[y][x];
      if (new_dist >= dists[new_y][new_x])
        continue;
      dists[new_y][new_x] = new_dist;
      to_visit.push(make_pair(dists[y][x], make_pair(new_y, new_x)));
    }
  }

  cout << dists[h - 1][w - 1] << endl;
}
