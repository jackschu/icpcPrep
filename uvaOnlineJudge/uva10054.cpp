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
int n;
int adj[50][50];
bool closed[50][50];
list<int> cyc;
void get_tour(list<int>::iterator i, int u) {

  for (int j = 0; j < 50; j++) {
    if (adj[u][j] <= 0)
      continue;
    adj[u][j]--;
    adj[j][u]--;
    auto nx = cyc.insert(i, u);
    get_tour(nx, j);
  }
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    cin >> n;
    if (ic != 0)
      cout << endl;
    printf("Case #%d\n", ic + 1);
    memset(adj, 0, sizeof adj);
    int *cts = new int[50]();
    int first = -1;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      if (first == -1)
        first = a;
      adj[a][b]++;
      adj[b][a]++;
      cts[a]++;
      cts[b]++;
    }
    bool lose = false;
    for (int i = 0; i < 50 && !lose; i++) {
      if (cts[i] % 2)
        lose = true;
    }

    if (lose) {
      cout << "some beads may be lost" << endl;
      continue;
    }
    for (int i = 0; i < 50 && !lose; i++)
      for (int j = 0; j < 50 && !lose; j++)
        closed[i][j] = adj[i][j];
    for (int k = 0; k < 50; k++)
      for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
          closed[i][j] |= closed[i][k] && closed[k][j];
    for (int i = 0; i < 50 && !lose; i++) {
      if (!cts[i])
        continue;
      for (int j = 0; j < 50 && !lose; j++) {
        lose |= !closed[i][j] && cts[j];
      }
    }
    delete[] cts;
    if (lose) {
      cout << "some beads may be lost" << endl;
      continue;
    }
    cyc.clear();
    get_tour(cyc.begin(), first);
    cout << first + 1;
    auto it = cyc.begin();
    for (; next(it) != cyc.end(); it++) {
      cout << " " << *it + 1 << endl << *it + 1;
    }
    cout << " " << *it + 1 << endl;
  }
}
