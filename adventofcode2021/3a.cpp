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

int main() {
  string l;
  int n;
  vector<string> rows;
  while (getline(cin, l)) {
    n = l.size();
    rows.push_back(l);
  }
  ll most = 0;
  ll least = 0;
  for (int i = 0; i < n; i++) {
    int tick = 0;
    for (auto &row : rows) {
      if (row[i] == '1')
        tick++;
      else
        tick--;
    }
    if (tick > 0)
      most += 1 << (n - i - 1);
    else
      least += 1 << (n - i - 1);
  }
  cout << most * least << endl;
}
