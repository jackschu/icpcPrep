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

int main() {
  int tc;
  cin >> tc;
  bool need[100];
  for (int ic = 0; ic < tc; ic++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      need[i] = c == '.';
    }
    int ct = 0;
    for (int i = 0; i < n; i++) {
      if (need[i]) {
        ct++;
        i += 2;
      }
    }
    printf("Case %d: %d\n", ic + 1, ct);
  }
}
