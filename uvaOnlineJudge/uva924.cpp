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
  int e;
  cin >> e;
  vector<vi> adj;
  for (int i = 0; i < e; i++) {
    int n;
    adj.push_back({});
    cin >> n;
    if (n == 0)
      continue;
    adj[i].reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(adj[i]));
  }
  int tc;
  cin >> tc;
  bool *visited = new bool[e];
  for (int ic = 0; ic < tc; ic++) {
    int a;
    cin >> a;
    vi ans;
    queue<ii> visit;
    fill_n(visited, e, 0);
    visit.push(ii(a, 0));
    visited[a] = true;
    int boomct = 0;
    int boomday = 0;
    bool spread = false;
    while (!visit.empty()) {
      ii u = visit.front();
      visit.pop();
      if (u.second != boomday) {
        DEBUG printf("day %d count %d\n", boomday, boomct);
        boomday = u.second;
        ans.push_back(boomct);

        boomct = 0;
      }
      boomct++;
      for (auto v : adj[u.first]) {
        if (visited[v])
          continue;
        spread = true;
        visited[v] = true;
        visit.push(ii(v, u.second + 1));
      }
    }
    ans.push_back(boomct);
    DEBUG printf("day %d count %d\n", boomday, boomct);
    ans[0] = -1;
    auto found = max_element(ans.begin(), ans.end());
    int d = distance(ans.begin(), found);
    int m = *found;
    if (!spread)
      cout << 0 << endl;
    else
      printf("%d %d\n", m, d);
  }
}
