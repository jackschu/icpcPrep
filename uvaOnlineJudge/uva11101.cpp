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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
int visited[2001][2001];
int main() {
  int p1;
  cin >> p1;

  while (p1) {
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < p1; i++) {
      int x, y;
      cin >> x >> y;
      visited[x][y] = 2;
    }
    queue<pair<ii, int>> q;
    int p2;
    cin >> p2;
    bool win = false;
    for (int i = 0; i < p2; i++) {
      int x, y;
      cin >> x >> y;
      if (visited[x][y] == 2 && !win) {
        win = true;
        cout << 1 << endl;
      }
      visited[x][y] = 1;
      q.push(pair<ii, int>(ii(x, y), 0));
    }

    while (!q.empty() && !win) {
      auto cur = q.front();
      q.pop();
      int x = cur.first.first;
      int y = cur.first.second;
      DEBUG printf("%d %d depth %d\n", x, y, cur.second);
      if (visited[x][y] == 2) {
        cout << cur.second << endl;
        break;
      }
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 2000 || ny < 0 || ny > 2000 || visited[nx][ny] == 1)
          continue;
        if (visited[nx][ny] == 0) {
          visited[nx][ny] = 1;
        }
        q.push(pair<ii, int>(ii(nx, ny), cur.second + 1));
      }
    }

    cin >> p1;
  }
}
