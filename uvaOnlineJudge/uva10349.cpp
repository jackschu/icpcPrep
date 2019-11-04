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
int h, w;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool board[40][10];
ii match[40][10];
bool seen[40][10];

int aug(ii p) {
  int r = p.first;
  int c = p.second;
  DEBUG printf("%d %d \n ", r, c);
  if (seen[r][c])
    return 0;
  seen[r][c] = 1;
  for (int d = 0; d < 4; d++) {
    int nr = r + dy[d];
    int nc = c + dx[d];
    if (nr < 0 || nc < 0 || nr >= h || nc >= w)
      continue;
    if (!board[nr][nc])
      continue;
    if (match[nr][nc] == ii(-1, -1) || aug(match[nr][nc])) {
      match[nr][nc] = p;
      return 1;
    }
  }
  return 0;
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    cin >> h >> w;
    vii l;
    int V = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        char x;
        cin >> x;
        board[i][j] = x == '*';
        if (x == '*') {
          V++;
          if ((i + j) % 2 == 0)
            l.push_back(ii(i, j));
        }
      }
    int mcbm = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        match[i][j] = ii(-1, -1);
    for (auto p : l) {
      memset(seen, 0, sizeof seen);
      mcbm += aug(p);
    }
    cout << V - mcbm << endl;
  }
}
