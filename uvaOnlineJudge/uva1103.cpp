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

int board[204][204];
int r, c;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs_seen[204][204];
int dfs(int y, int x, int targ, int fill = -1, bool boom = false) {
  if (y < 0 || y >= r || x < 0 || x >= c || dfs_seen[y][x])
    return 0;
  if (boom && board[y][x] == 0) {
    dfs(y, x, 0, -1, false);
    return 1;
  }
  if (board[y][x] != targ) {
    return 0;
  }
  if (fill != -1)
    board[y][x] = fill;
  dfs_seen[y][x] = 1;
  int out = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    out += dfs(ny, nx, targ, fill, boom);
  }
  return out;
}

int main() {
  cin >> r >> c;
  int ic =0;
  while (r | c) {
    ic++;
    c *= 4;
    memset(board, 0, sizeof board);

    for (int i = 1; i < r+1; i++) {
      for (int j = 1; j < c+1; j += 4) {
        char cur;
        cin >> cur;
        int x;
        if (isdigit(cur)) {
          x = int(cur - '0');
        } else {
          x = int(cur - 'a') + 10;
        }
        board[i][j] = (x & (1 << 3)) != 0;
        board[i][j + 1] = (x & (1 << 2)) != 0;
        board[i][j + 2] = (x & (1 << 1)) != 0;
        board[i][j + 3] = (x & 1) != 0;
      }
    }
    r+=2;
    c+=2;
    memset(dfs_seen, 0, sizeof dfs_seen);
    int cc = 0;
    vii reps;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (board[i][j] == 0 || dfs_seen[i][j] != 0)
          continue;
        cc++;
        reps.push_back(ii(i, j));
        dfs(i, j, 1);
      }
    }
    memset(dfs_seen, 0, sizeof dfs_seen);
    dfs(0, 0, 0, 3);
    string s = "";
    vector<string> translations = {"W","A", "K", "J", "S","D"};
    for (auto rep : reps) {
      memset(dfs_seen, 0, sizeof dfs_seen);
      string c;
      int res = dfs(rep.first, rep.second, 1, -1, true);
      s+=translations[res];
    }
    sort(s.begin(), s.end());
    printf("Case %d: ", ic);
    cout<<s<<endl;

    cin >> r >> c;
  }
}
