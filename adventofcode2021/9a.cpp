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

bool isLocalMin(int board[104][104], int x, int y, int h, int w) {
  vi dx = {1, -1, 0, 0};
  vi dy = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    int cur_x = x + dx[i];
    int cur_y = y + dy[i];
    if (cur_x < 0 || cur_x >= w)
      continue;
    if (cur_y < 0 || cur_y >= h)
      continue;
    if (board[y][x] >= board[cur_y][cur_x])
      return false;
  }
  return true;
}

int main() {
  string l;
  int board[104][104];
  memset(board, 0, sizeof board);
  int h = 0;
  while (getline(cin, l)) {
    for (int i = 0; i < l.size(); i++) {
      board[h][i] = l[i] - '0';
    }
    h++;
  }
  int w = l.size();
  int out = 0;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (!isLocalMin(board, j, i, h, w))
        continue;
      DEBUG printf(" %d, %d : %d\n", j, i, board[i][j]);
      out += board[i][j] + 1;
    }
  cout << out << endl;
}
