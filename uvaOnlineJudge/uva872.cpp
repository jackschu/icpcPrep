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

vector<char> cur;
vector<vi> adj;
bool visited[26];
int ct;
bool stop;
void backtrack() {
  bool every = true;
  for (int i = 0; i < 26; i++) {
    if (visited[i])
      continue;
    every = false;
    bool go = true;
    for (auto elem : adj[i]) {
      if (!visited[elem]) {
        go = false;
        break;
      }
    }
    if (!go)
      continue;
    visited[i] = true;
    cur.push_back(char(i + 'A'));
    backtrack();
    if (stop)
      return;
    cur.pop_back();
    visited[i] = false;
  }
  if (every) {
    ct++;
    if (ct > 300)
      stop = true;
    int n = cur.size();
    for (int i = 0; i < n; i++) {
      if (i != 0)
        cout << " ";
      cout << cur[i];
    }
    cout << endl;
  }
}

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  for (int ic = 0; ic < tc; ic++) {
    stop = false;
    if (ic != 0)
      cout << endl;
    memset(visited, true, sizeof visited);
    ct = 0;
    cur.clear();
    cur.reserve(26);
    string vars;
    getline(cin, vars);
    getline(cin, vars);
    int n = vars.size();
    for (int i = 0; i < n; i += 2) {
      visited[int(vars[i] - 'A')] = false;
    }
    adj.clear();
    adj.reserve(26);
    for (int i = 0; i < 26; i++) {
      adj.push_back({});
    }
    getline(cin, vars);
    n = vars.size();
    for (int i = 0; i + 2 < n; i += 4) {
      adj[int(vars[i + 2] - 'A')].push_back(int(vars[i] - 'A'));
    }
    backtrack();
    if (ct == 0)
      cout << "NO" << endl;
  }
}
