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

char board[22][22];
bool dfs_seen[22][22];
int m, n;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int flood(int y, int x, char c1, char c2) {
  DEBUG printf("%d %d\n", y, x);
  if (x == n)
    x = 0;
  if (x == -1)
    x = n - 1;
  if (y < 0 || y >= m || dfs_seen[y][x])
    return 0;
  if (board[y][x] != c1)
    return 0;
  board[y][x] = c2;
  dfs_seen[y][x] = true;
  int out = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    out += flood(ny, nx, c1, c2);
  }
  return out;
}

int main() {
  while (cin >> m >> n) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        board[i][j] = c;
      }
    }

    int sy, sx;
    cin >> sy >> sx;
    char land = board[sy][sx];
    memset(dfs_seen, false, sizeof dfs_seen);
    flood(sy, sx, land, 'w');
    int mx = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == land) {
          mx = max(mx, flood(i, j, land, 'w'));
        }
      }
    }
    cout << mx << endl;
  }
}
