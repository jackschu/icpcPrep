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
  ll mem[5][30003];
  vi coins = {50, 25, 10, 5, 1};
  for (int i = 0; i < 30001; i++) {
    mem[4][i] = 1;
  }
  for (int i = 3; i >= 0; i--) {
    for (int j = 0; j < 30001; j++) {
      ll cur = j - coins[i] >= 0 ? mem[i][j - coins[i]] : 0;
      ll next = mem[i + 1][j];
      mem[i][j] = cur + next;
    }
  }
  int x;
  while (cin >> x) {
    ll out = mem[0][x];
    if (out == 1) {
      printf("There is only %lld way to produce %d cents change.\n", out, x);
    } else {
      printf("There are %lld ways to produce %d cents change.\n", out, x);
    }
  }
}
