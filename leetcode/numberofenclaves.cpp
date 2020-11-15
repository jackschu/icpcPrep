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

int numEnclaves(vector<vector<int>> &board);
int main() {
  std::vector<std::vector<int>> ans2{
      {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  std::vector<std::vector<int>> ans3{
      {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  cout << numEnclaves(ans2) << endl;
  cout << numEnclaves(ans3) << endl;
}

int numEnclaves(vector<vector<int>> &board) {
  int dy[] = {0, 0, 1, -1};
  int dx[] = {1, -1, 0, 0};

  int h = board.size();
  int w = board[0].size();

  queue<ii> visit;

  for (int i : {0, h - 1})
    for (int j = 0; j < w; j++)
      if (board[i][j]) {
        visit.push(ii(i, j));
        board[i][j] = 0;
      }

  for (int j : {0, w - 1})
    for (int i = 0; i < h; i++)
      if (board[i][j]) {
        visit.push(ii(i, j));
        board[i][j] = 0;
      }

  while (!visit.empty()) {
    ii u = visit.front();
    visit.pop();
    for (int d = 0; d < 4; d++) {
      int nr = u.first + dy[d];
      int nc = u.second + dx[d];
      if (nr < 0 || nc < 0 || nr >= h || nc >= w)
        continue;
      if (!board[nr][nc])
        continue;
      board[nr][nc] = 0;
      visit.push(ii(nr, nc));
    }
  }
  int out = 0;
  for (int i = 1; i < h - 1; i++)
    for (int j = 1; j < w - 1; j++) {
      if (!board[i][j])
        continue;
      out++;
    }
  return out;
}
