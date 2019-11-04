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
int match[500];
bool seen[500];

int aug(int l) {
  if (seen[l])
    return 0;
  seen[l] = true;
  for (auto r : adj[l]) {
    if (match[r] == -1 || aug(match[r])) {
      match[r] = l;
      return 1;
    }
  }
  return 0;
}
int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int ln, rn;
    cin >> ln >> rn;
    adj.clear();
    adj.reserve(ln);
    for (int i = 0; i < ln; i++)
      adj.push_back({});
    for (int i = 0; i < ln; i++) {
      for (int j = 0; j < rn; j++) {
        int x;
        cin >> x;
        if (x == 1)
          adj[i].push_back(j);
      }
    }
    int mcbm = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < ln; i++) {
      memset(seen, 0, sizeof seen);
      mcbm += aug(i);
    }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",
           ic + 1, mcbm);
  }
}
