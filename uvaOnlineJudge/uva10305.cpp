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
vector<vi> adj;
vi ans;
bool visited[102];
int n;
void dfs(int idx) {  
  for(auto i : adj[idx]){
    if (visited[i])
      continue;
    visited[i] = true;
    dfs(i);
  }
  ans.push_back(idx);
}

int main() {
  int m;
  cin >> n >> m;
  while (n | m) {
    memset(visited, 0, sizeof visited);
    adj.clear();
    ans.clear();
    ans.reserve(n);
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        dfs(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != 0)
        cout << " ";
      cout << ans[i] + 1;
    }
    cout << endl;
    cin >> n >> m;
  }
}
