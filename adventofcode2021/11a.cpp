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

void printBoard(const vector<vi> &board) {
  for (auto row : board) {
    for (auto elem : row)
      cout << (elem > 9 ? 'X' : char(elem + '0'));
    cout << endl;
  }
}

int runStep(vector<vi> &board) {
  int n = board.size();
  queue<ii> to_pulse;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      board[i][j]++;
      if (board[i][j] == 10) {
        to_pulse.push(make_pair(i, j));
      }
    }
  int out = 0;
  vi dx = {1, -1, 0, 0, 1, 1, -1, -1};
  vi dy = {0, 0, 1, -1, -1, 1, 1, -1};
  while (!to_pulse.empty()) {
    auto cur = to_pulse.front();
    to_pulse.pop();
    if (board[cur.first][cur.second] == 0)
      continue;

    board[cur.first][cur.second] = 0;

    out++;
    for (int i = 0; i < dx.size(); i++) {

      int cur_y = cur.first + dy[i];
      int cur_x = cur.second + dx[i];

      if (min(cur_y, cur_x) < 0 || max(cur_y, cur_x) >= n)
        continue;
      if (board[cur_y][cur_x] == 0)
        continue;

      board[cur_y][cur_x]++;
      if (board[cur_y][cur_x] > 9) {
        to_pulse.push(make_pair(cur_y, cur_x));
      }
    }
  }
  return out;
}

int main() {
  vector<vi> board;
  string l;
  int n = 0;
  while (getline(cin, l)) {
    n = l.size();
    vi build;
    build.reserve(n);
    for (auto elem : l)
      build.push_back(elem - '0');
    board.push_back(build);
  }
  int iters = 100;
  ll out = 0;
  for (int i = 0; i < iters; i++)
    out += runStep(board);

  cout << out << endl;
}
