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
bool adj[202][202];
int main() {

  int nc;
  cin >> nc;
  int ic = 0;
  while (nc) {
    unordered_map<string, int> m;
    memset(adj, 0, sizeof adj);
    vector<string> vs;
    int msz = 0;
    for (int i = 0; i < nc; i++) {
      int ne;
      cin >> ne;
      int a = -1, b = -1;
      for (int j = 0; j < ne; j++) {
        a = b;
        string s;
        cin >> s;
        auto f = m.find(s);

        if (f == m.end()) {
          vs.push_back(s);
          m[s] = msz;
          b = msz;
          msz++;
        } else {
          b = f->second;
        }
        if (j != 0) {
          adj[a][b] = true;
        }
      }
    }
    int nm;
    cin >> nm;
    for (int i = 0; i < nm; i++) {
      string as, bs;
      cin >> as >> bs;
      adj[m[as]][m[bs]] = true;
    }
    for (int k = 0; k < msz; k++) {
      for (int i = 0; i < msz; i++) {
        for (int j = 0; j < msz; j++) {
          adj[i][j] |= adj[i][k] && adj[k][j];
        }
      }
    }
    int ct = 0;
    pair<string, string> out1, out2;
    for (int i = 0; i < msz; i++) {
      for (int j = i + 1; j < msz; j++) {
        if (!adj[i][j] && !adj[j][i]) {
          if (ct == 0)
            out1 = pair<string, string>(vs[i], vs[j]);
          if (ct == 1)
            out2 = pair<string, string>(vs[i], vs[j]);
          ct++;
        }
      }
    }

    if (ct) {
      printf("Case %d, %d concurrent events:\n", ++ic, ct);
      if (ct == 1)
        printf("(%s,%s) \n", out1.first.c_str(), out1.second.c_str());
      else
        printf("(%s,%s) (%s,%s) \n", out1.first.c_str(), out1.second.c_str(),
               out2.first.c_str(), out2.second.c_str());

    } else
      printf("Case %d, no concurrent events.\n", ++ic);

    cin >> nc;
  }
}
