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

int board[100][100];
int r, c, m, n;

bool isvalid(int y, int x) {
  if (x < 0 || x >= c || y < 0 || y >= r)
    return false;
  if (board[y][x] < 0)
    return false;
  return true;
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    memset(board, 0, sizeof board);
    cin >> r >> c >> m >> n;
    int w;
    cin >> w;
    for (int i = 0; i < w; i++) {
      int x, y;
      cin >> y >> x;
      board[y][x] = -2;
    }
    board[0][0] = 3; // visited
    queue<ii> visit;
    int odd = 0, even = 0;
    visit.push(ii(0, 0));
    while (!visit.empty()) {
      ii cur = visit.front();
      visit.pop();
      set<ii> tries = {ii(m, n), ii(-m, n), ii(-m, -n), ii(m, -n),
                       ii(n, m), ii(-n, m), ii(-n, -m), ii(n, -m)};
      int ct = 0;
      for (auto elem : tries) {
        int x = cur.second + elem.second;
        int y = cur.first + elem.first;
        if (!isvalid(y, x))
          continue;
        ct++;
        if (board[y][x] != 3) {
          board[y][x] = 3;
          visit.push(ii(y, x));
        }
      }
      if (ct % 2 == 0)
        even++;
      else
        odd++;
    }
    printf("Case %d: %d %d\n", ic + 1, even, odd);
  }
}
