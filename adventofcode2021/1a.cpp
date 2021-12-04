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
  cout << "startin" << endl;
  int prev, cur;
  int out;
  while (cin >> cur) {
    if (first) {
      prev = cur;
      first = false;
      continue;
    }
    if (prev < cur) {
      printf("%d %d\n", prev, cur);
      out++;
    }

    prev = cur;
  }
  cout << out << endl;
}
