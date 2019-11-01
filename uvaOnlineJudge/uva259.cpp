#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
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
int flow[38][38];
int p[38];
int n = 38;
vector<vi> adj;
int f;
int s = 36, t = 37;

void augment(int cur, int minEdg) {
  if (cur == s) {
    f = minEdg;
    return;
  } else if (p[cur] != -1) {
    augment(p[cur], min(flow[p[cur]][cur], minEdg));
    flow[p[cur]][cur] -= f;
    flow[cur][p[cur]] += f;
  }
}

int main() {
  // indexes 0-9, then A-Z then src(36) snk(37)
  string l;
  int inf = 1e9;

  while (getline(cin, l)) {
    stringstream ss;

    bool eof = false;
    while (l.size() > 1) {
      ss << l;
      if (!getline(cin, l))
        eof = true;
    }
    memset(flow, 0, sizeof flow);
    adj.clear();

    adj.reserve(n);
    for (int i = 0; i < n; i++) {
      adj.push_back({});
    }
    for (int i = 0; i < 10; i++) {
      adj[i].push_back(37);
      adj[37].push_back(i);
      flow[i][37] = 1;
    }
    char c;
    int targmf = 0;
    while (ss >> c) {
      int a = c - 'A' + 10;
      int nc;
      ss >> nc;
      char bc;
      ss >> bc;
      while (bc != ';') {
        int b = bc - '0';
        adj[a].push_back(b);
        adj[b].push_back(a);
        flow[a][b] = 1;
        ss >> bc;
      }
      adj[36].push_back(a);
      adj[a].push_back(36);
      flow[36][a] = nc;
      targmf += nc;
    }
    DEBUG cout << " targ " << targmf << endl;
    // for (int i = 0; i < 38; i++) {
    //   for (int j = 0; j < 38; j++)
    //     cout << flow[i][j] << " ";
    //   cout << endl;
    // }
    int mf = 0;
    while (true) {
      queue<int> q;
      memset(p, -1, sizeof p);
      q.push(36);
      bitset<38> seen;
      seen[36] = true;
      f = 0;
      while (!q.empty()) {

        int u = q.front();
        q.pop();
        if (u == t)
          break;
        for (auto v : adj[u]) {
          if (seen[v])
            continue;
          if (flow[u][v] > 0) {
            p[v] = u;
            seen[v] = true;
            q.push(v);
          }
        }
      }
      augment(t, inf);
      if (f == 0)
        break;
      mf += f;
      DEBUG printf("flow %d\n", mf);
    }

    if (targmf == mf) {
      for (int i = 0; i < 10; i++) {
        bool got = false;
        for (int j = 10; j < 36; j++) {
          if (flow[i][j] == 1) {
            cout << char(j - 10 + int('A'));
            got = true;
            break;
          }
        }
        if (!got)
          cout << "_";
      }
      cout << endl;
    } else
      cout << "!" << endl;

    if (eof)
      break;
  }
}
