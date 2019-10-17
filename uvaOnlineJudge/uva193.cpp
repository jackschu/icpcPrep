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
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (true)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bitset<100> taken;
deque<int> black;
int n;
int ct;
int mx;
vi best;
vector<vi> adj;

void backtrack(int c) {
  DEBUG printf("c:%d  s:%d\n", c, int(black.size()));
  if (c >= n) {
    if (ct > mx) {
      mx = ct;
      best.assign(black.begin(), black.end());
    }
    return;
  }

  if (!taken[c]) {
    bitset<100> save = taken;
    black.push_front(c);
    ct++;
    for (auto elem : adj[c]) {
      taken.set(elem);
    }
    backtrack(c + 1);
    taken = save;
    ct--;
    black.pop_front();
  }
  backtrack(c + 1);
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    int k;
    cin >> n >> k;
    adj.clear();
    ct = 0;
    mx = 0;
    adj.reserve(n);
    for (int i = 0; i < n; i++) {
      adj.push_back({});
    }
    taken.reset();
    black.clear();

    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      adj[a - 1].push_back(b - 1);
      adj[b - 1].push_back(a - 1);
    }
    backtrack(0);
    cout << mx << endl;
    for (int i = 0; i < mx; i++) {
      if (i != 0)
        cout << " ";
      cout << best[i] + 1;
    }
    cout << endl;
  }
}
