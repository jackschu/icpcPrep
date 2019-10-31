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
ll adj[100][100];
int main() {
  int a, b;
  int e = 3;
  int ic = 0;
  while (e) {
    cin >> a >> b;

    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++)
        adj[i][j] = 1e7;
    e = 0;
    while (a | b) {
      a--;
      b--;
      adj[a][b] = 1;
      e++;
      cin >> a >> b;
    }
    if (e == 0)
      break;
    for (int k = 0; k < 100; k++)
      for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int len = 0;
    int ct = 0;
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        if (i == j || adj[i][j] == 1e7)
          continue;
        len += adj[i][j];
        ct++;
      }
    double out = double(len) / double(ct);
    printf("Case %d: average length between pages = %.3lf clicks\n", ++ic, out);
  }
}
