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
int out = 0;
void run(bool *nb, int a, int b) {
  if (a > b)
    return;
  out++;
  bool cur = nb[a];

  for (int i = a; i <= b; i++) {
    if (nb[i] != cur) {
      run(nb, a, (a + b + 1) / 2 - 1);
      run(nb, (a + b + 1) / 2, b);
      break;
    }
  }
}
int main() {
  int n;
  cin >> n;
  ll sz = 1 << n;
  bool *b = new bool[sz];
  bool *nb = new bool[sz];
  for (ll i = 0; i < sz; i++) {
    bool x;
    cin >> x;
    b[i] = x;
  }
  for (int i = sz; i >= 0; i--) {
    ll x = 0;
    for (int j = 0; j < n; j++) {
      x |= (!(i & 1 << j)) << (n - 1 - j);
    }
    nb[x] = b[i];
  }
  run(nb, 0, sz - 1);
  cout << out << endl;
}
