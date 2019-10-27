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

int num[26], low[26];
vi s;
int dfsnum;
int visited[26];
vector<vi> ans;
void dfs(int u) {
  DEBUG cout << u << endl;
  num[u] = low[u] = dfsnum++;
  s.push_back(u);
  visited[u] = 1;
  for (auto v : adj[u]) {
    if (num[v] == -1) {
      dfs(v);
    }
    if (visited[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  DEBUG cout << " recursed " << endl;
  if (low[u] == num[u]) {
    vi cur;
    while (true) {
      DEBUG cout << s.size() << endl;
      int bk = s.back();
      s.pop_back();
      visited[bk] = 0;
      cur.push_back(bk);
      if (u == bk)
        break;
    }
    ans.push_back(cur);
  }
  DEBUG cout << " returned " << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  int ic = 0;
  while (n | m) {
    if (ic != 0)
      cout << endl;
    printf("Calling circles for data set %d:\n", ++ic);
    if (m == 0 || n == 0) { // needed since otherwise dont know names
      cin >> n >> m;
      continue;
    }
    ans.clear();
    map<string, int> name_to_int;
    vector<string> int_to_name;
    adj.clear();
    s.clear();
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    int ct = 0;
    for (int i = 0; i < m; i++) {
      string as, bs;
      cin >> as >> bs;
      auto fa = name_to_int.find(as);
      auto fb = name_to_int.find(bs);
      bool na = fa == name_to_int.end();
      bool nb = fb == name_to_int.end();
      int a, b;
      if (!na)
        a = fa->second;
      if (!nb)
        b = fb->second;

      if (na) {
        a = ct;
        name_to_int[as] = ct++;

        int_to_name.push_back(as);
      }
      if (nb) {
        b = ct;
        name_to_int[bs] = ct++;
        int_to_name.push_back(bs);
      }
      adj[a].push_back(b);
    }
    DEBUG cout << "input processed" << endl;
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    memset(visited, 0, sizeof visited);
    dfsnum = 0;
    for (int i = 0; i < n; i++) {
      if (num[i] == -1) {
        dfs(i);
      }
    }
    for (auto &circ : ans) {
      int sz = circ.size();
      for (int i = 0; i < sz; i++) {
        if (i != 0)
          cout << ", ";
        cout << int_to_name[circ[i]];
      }
      cout << endl;
    }
    cin >> n >> m;
  }
}
