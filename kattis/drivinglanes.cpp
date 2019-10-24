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
vi st;
vii cv;
ll mem[255][255];
int r, k;
int m;
ll cost(int n, int l) {
  DEBUG printf("%d %d\n", n, l);
  if (n == -1) {
    if (l == 1)
      return 0;
    else
      return -1;
  }

  if (mem[n][l] != 0)
    return mem[n][l];
  ll out = -1;
  for (int i = 1; i <= m; i++) {
    if (abs(i - l) * k > st[n])
      continue;
    ll cur = cost(n - 1, i);
    if (cur == -1)
      continue;
    cur += abs(i - l) * r + st[n];
    cur += cv[n].first + cv[n].second * l;
    if (out == -1 || out > cur) {
      out = cur;
    }
  }
  return mem[n][l] = out;
}

int main() {
  memset(mem, 0, sizeof mem);
  int n;
  cin >> n >> m;
  cin >> k >> r;
  st.reserve(n);
  cv.reserve(n + 1);
  copy_n(istream_iterator<int>(cin), n, back_inserter(st));

  for (int i = 0; i < n - 1; i++) {
    int s, c;
    cin >> s >> c;
    cv.push_back(ii(s, c));
  }
  cv.push_back(ii(0, 0));

  cout << cost(n - 1, 1) << endl;
}
