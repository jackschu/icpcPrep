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

char orient;
int x, y;
int n, m;
int ct;

char board[100][100];

void forward() {
  ii offset;
  switch (orient) {
  case 'N':
    offset = ii(-1, 0);
    break;
  case 'E':
    offset = ii(0, 1);
    break;
  case 'S':
    offset = ii(1, 0);
    break;
  case 'W':
    offset = ii(0, -1);
    break;
  }
  int ny = y + offset.first;
  int nx = x + offset.second;
  if (ny < 0 || ny >= n || nx >= m || nx < 0)
    return;
  if (board[ny][nx] == '#')
    return;
  if (board[ny][nx] == '*')
    ct++;
  board[ny][nx] = '.';
  x = nx;
  y = ny;
  return;
}

void rotate_left() {
  switch (orient) {
  case 'N':
    orient = 'W';
    break;
  case 'E':
    orient = 'N';
    break;
  case 'S':
    orient = 'E';
    break;
  case 'W':
    orient = 'S';
    break;
  }
}

void rotate_right() {
  switch (orient) {
  case 'N':
    orient = 'E';
    break;
  case 'E':
    orient = 'S';
    break;
  case 'S':
    orient = 'W';
    break;
  case 'W':
    orient = 'N';
    break;
  }
}

int main() {
  int s;
  cin >> n >> m >> s;
  while (n | m | s) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == 'N' || c == 'S' || c == 'L' || c == 'O') {
          if (c == 'L')
            c = 'E';
          if (c == 'O')
            c = 'W';
          orient = c;
          y = i;
          x = j;
          c = '.';
        }
        board[i][j] = c;
      }
    }
    ct = 0;
    for (int i = 0; i < s; i++) {
      char c;
      cin >> c;
      switch (c) {
      case 'D':
        rotate_right();
        break;
      case 'E':
        rotate_left();
        break;
      case 'F':
        forward();
        break;
      }
    }
    cout << ct << endl;
    cin >> n >> m >> s;
  }
}
