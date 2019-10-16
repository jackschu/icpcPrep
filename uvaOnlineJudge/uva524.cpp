#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
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
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

vi works;
bool taken[20];
int out[20];
int n;
void backtrack(int c) {
  if (c == n && primes.find(out[c - 1] + 1) != primes.end()) {
    cout << 1;
    for (int i = 1; i < n; i++) {
      cout << " " << out[i];
    }
    cout << endl;
  }

  for (int i = 2; i <= n; i++) {
    if (taken[i - 1] || (c != 0 && primes.find(out[c - 1] + i) == primes.end()))
      continue;
    taken[i - 1] = true;
    out[c] = i;
    backtrack(c + 1);
    taken[i - 1] = false;
  }
}

int main() {
  int ic = 0;
  while (cin >> n) {
    if (ic != 0)
      cout << endl;
    printf("Case %d:\n", ++ic);
    fill_n(taken, 20, 0);
    fill_n(out, 20, 0);
    out[0] = 1;
    taken[0] = 1;
    works.clear();
    works.reserve(n);
    backtrack(1);
  }
}
