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

int main() {
  int n, m;
  map<string, int> dirs;
  dirs["north"] = 0;
  dirs["east"] = 1;
  dirs["south"] = 2;
  dirs["west"] = 3;
  vii ds = {ii(-1, 0), ii(0, 1), ii(1, 0), ii(0, -1)};
  cin >> m >> n;
  vi dr = {1, -1, 0, 0, 0};
  vi df = {0, 0, 1, 2, 3};
  while (m | n) {
    set<pair<int, ii>> visited, blocked;

    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        int b;
        cin >> b;
        if (b == 0)
          continue;
        for (int i = 0; i < 4; i++) {
          blocked.insert(pair<int, ii>(i, ii(y, x)));
          blocked.insert(pair<int, ii>(i, ii(y + 1, x)));
          blocked.insert(pair<int, ii>(i, ii(y + 1, x + 1)));
          blocked.insert(pair<int, ii>(i, ii(y, x + 1)));
        }
      }
    }

    int b1, b2, e1, e2;
    string st_dir;
    cin >> b1 >> b2 >> e1 >> e2 >> st_dir;
    queue<pair<int, ii>> q;
    queue<int> depth;
    pair<int, ii> start = pair<int, ii>(dirs[st_dir], ii(b1, b2));
    ii stop = ii(e1, e2);
    // map< pair<int, ii>, pair<int, ii>> parent;
    if (blocked.find(start) != blocked.end()) {
      cout << -1 << endl;
      cin >> m >> n;
      continue;
    }
    depth.push(0);
    q.push(start);
    visited.insert(start);
    int out = -1;
    int enddir;
    // for(int i = 0 ; i <= m ; i++){
    //   for(int j = 0 ; j <= n ; j++){
    // 	if(i == b1 && j == b2)
    // 	  cout << "S" << " ";
    // 	else 	if(i == e1 && j == e2)
    // 	  cout << "F" << " ";
    // 	else
    // 	cout << int(blocked.find(pair<int, ii> (0, ii(i, j))) !=
    // blocked.end())<< " ";
    //   }
    //   cout << endl;
    // }
    while (!q.empty()) {
      pair<int, ii> u = q.front();
      q.pop();
      int d = depth.front();
      depth.pop();
      DEBUG cout << d << endl;
      int y = u.second.first;
      int x = u.second.second;
      DEBUG printf("dir %d y %d x %d\n", u.first, y, x);
      if (y <= 0 || y >= m || x <= 0 || x >= n)
        continue;
      if (u.second == stop) {
        out = d;
        enddir = u.first;
        break;
      }
      for (int i = 0; i < 5; i++) {
        pair<int, ii> next = u;
        next.second.first += ds[next.first].first * df[i];
        next.second.second += ds[next.first].second * df[i];

        next.first = (next.first + dr[i]) % 4;
        if (next.first < 0)
          next.first += 4;
        if (i == 4) {
          pair<int, ii> block = next;
          block.second.first -= ds[next.first].first;
          block.second.second -= ds[next.first].second;
          if (blocked.find(block) != blocked.end())
            continue;
        }
        if (visited.find(next) == visited.end() &&
            blocked.find(next) == blocked.end()) {
          // parent[next] = u;
          visited.insert(next);
          q.push(next);
          depth.push(d + 1);
        }
      }
    }
    // pair<int, ii> cur =pair<int, ii >(enddir,stop);
    // while(cur!= start){
    //   printf("dir %d y %d x %d\n", cur.first, cur.second.first,
    //   cur.second.second); cur = parent[cur];
    // }
    cout << out << endl;
    cin >> m >> n;
  }
}
