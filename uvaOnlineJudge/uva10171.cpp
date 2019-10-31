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

ll adjy[26][26];
ll adjm[26][26];

int main() {
  int n;
  cin >> n;
  int inf = 1e9;
  while (n) {
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) {
        adjy[i][j] = inf;
        adjm[i][j] = inf;
      }

    for (int i = 0; i < n; i++) {
      char who, dir, a, b;
      int c;
      cin >> who >> dir >> a >> b >> c;

      if (who == 'Y') {
        adjy[int(a - 'A')][int(b - 'A')] = c;
        if (dir == 'B')
          adjy[int(b - 'A')][int(a - 'A')] = c;
      } else {
        adjm[int(a - 'A')][int(b - 'A')] = c;
        if (dir == 'B')
          adjm[int(b - 'A')][int(a - 'A')] = c;
      }
    }

    char yp, mp;
    // cout << n;
    cin >> yp >> mp;
    int y = yp - 'A', m = mp - 'A';
    adjy[y][y] = 0;
    adjm[m][m] = 0;
    for (int k = 0; k < 26; k++)
      for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
          adjy[i][j] = min(adjy[i][j], adjy[i][k] + adjy[k][j]);
          adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
        }
    ll out = inf;
    vi outc;
    for (int k = 0; k < 26; k++) {
      ll opt = adjy[y][k] + adjm[m][k];
      if (out > opt) {
        out = opt;
        outc.clear();
        outc.push_back(k);
      } else if (out == opt) {
        outc.push_back(k);
      }
    }
    if (out != inf) {
      cout << out;
      for (auto i : outc)
        cout << " " << char(int('A') + i);
      cout << endl;
    } else
      cout << "You will never meet." << endl;

    cin >> n;
  }
}
