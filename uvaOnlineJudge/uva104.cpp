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

double adj[26][26][26];
int parent[26][26][26];

int main() {
  int n;
  while (cin >> n) {
    vi ans;
    bool win = false;
    memset(adj, 0, sizeof adj);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          adj[i][j][0] = 1;
        else {
          double x;
          cin >> x;
          adj[i][j][0] = x;
        }
      }
    }
    for (int s = 1; s < n; s++) {
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            double opt = adj[i][k][s - 1] * adj[k][j][0];
            if (adj[i][j][s] < opt) {
              adj[i][j][s] = opt;
              parent[i][j][s] = k;
            }
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (adj[i][i][s] >= 1.01) {

          int p = i;
          for (int j = s; j >= 0; j--) {
            ans.push_back(p + 1);
            p = parent[i][p][j];
          }
          ans.push_back(i + 1);
          reverse(ans.begin(), ans.end());
          win = true;
          break;
        }
      }
      if (win)
        break;
    }
    if (win) {
      for (int i = 0; i < ans.size(); i++) {
        if (i != 0)
          cout << " ";
        cout << ans[i];
      }
      cout << endl;
    } else {
      cout << "no arbitrage sequence exists" << endl;
    }
  }
}
