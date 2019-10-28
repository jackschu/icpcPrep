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

bool strdist(const string &a, const string &b) {
  int n = a.size();
  if (b.size() != n)
    return false;
  int diffct = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i])
      continue;
    if (diffct != 0)
      return false;
    diffct++;
  }
  return true;
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    if (ic != 0)
      cout << endl;
    string s;
    vector<string> words;
    vector<vi> adj;
    map<string, int> str_int;
    cin >> s;
    int len = 0;
    while (s != "*") {
      words.push_back(s);
      str_int[s] = len++;
      cin >> s;
    }

    int n = words.size();
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (strdist(words[i], words[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    bool *visited = new bool[n];
    string l;
    cin.ignore();
    getline(cin, l);
    while (l.size() > 1) {
      stringstream ss(l);
      string as, bs;
      ss >> as >> bs;
      int a = str_int[as];
      int b = str_int[bs];
      if (a == b) {
        cout << as << " " << bs << " " << 0 << endl;
        getline(cin, l);
        continue;
      }
      fill_n(visited, n, 0);
      queue<ii> visit;
      visit.push(ii(a, 0));
      visited[a] = true;
      int dist = -1;
      while (!visit.empty()) {
        ii u = visit.front();
        visit.pop();
        for (auto v : adj[u.first]) {
          if (visited[v])
            continue;
          visited[v] = true;
          if (v == b) {
            dist = u.second + 1;
            break;
          }
          visit.push(ii(v, u.second + 1));
        }
        if (dist != -1)
          break;
      }
      cout << as << " " << bs << " " << dist << endl;
      getline(cin, l);
    }
    delete[] visited;
  }
}
