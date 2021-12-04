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
  bool first = true;
  vi vals;
  int x;
  while (cin >> x)
    vals.push_back(x);
  int out = 0;
  for (int i = 3; i < vals.size(); i++) {
    int prev = vals[i - 3] + vals[i - 2] + vals[i - 1];
    int cur = vals[i - 2] + vals[i - 1] + vals[i];
    if (cur > prev)
      out++;
  }
  cout << out << endl;
}
