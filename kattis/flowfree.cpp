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
char board[4][4];
char col[] = {'R', 'G', 'B', 'Y'};
bool yel = false;
bool out = false;
bool visited[4][4];
vii start;
vii stop;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void backtrack(ii cur, ii targ, int iter = 1) {
  DEBUG printf("%d %d %d\n", cur.first, cur.second, iter);
  DEBUG printf("t%d %d %d\n", targ.first, targ.second, iter);
  board[cur.first][cur.second] = board[targ.first][targ.second];
  if (cur == targ) {

    if (iter < (yel ? 4 : 3)) {
      backtrack(start[iter], stop[iter], iter + 1);
    } else {
      out = true;
      for (int i = 0; i < 4 && out; i++) 
        for (int j = 0; j < 4 && out; j++)
          if (board[i][j] == 'W')
            out = false;
    }
    return;
  }
  for (int i = 0; i < 4 && !out; i++) {
    int nx = cur.first + dx[i];
    int ny = cur.second + dy[i];
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
      continue;
    if (board[nx][ny] != 'W' && ii(nx, ny) != targ)
      continue;
    backtrack(ii(nx, ny), targ, iter);
  }
  if (cur != targ && cur != start[iter - 1]) {
    board[cur.first][cur.second] = 'W';
  }
}

int main() {
  bool b = false, r = false, g = false;
  for (int i = 0; i < 4; i++) {
    start.push_back(ii(0, 0));
    stop.push_back(ii(0, 0));
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      char c;
      cin >> c;
      if (c == 'Y') {
        if (yel)
          stop[3] = (ii(i, j));
        else
          start[3] = (ii(i, j));
        yel = true;
      } else if (c == 'R') {
        if (r)
          stop[0] = (ii(i, j));
        else
          start[0] = (ii(i, j));
        r = true;
      } else if (c == 'G') {
        if (g)
          stop[1] = (ii(i, j));
        else
          start[1] = (ii(i, j));
        g = true;
      } else if (c == 'B') {
        if (b)
          stop[2] = (ii(i, j));
        else
          start[2] = (ii(i, j));
        b = true;
      }
      board[i][j] = c;
    }

  backtrack(start[0], stop[0]);
  if (out)
    cout << "solvable" << endl;
  else
    cout << "not solvable" << endl;
}
