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

ll calcCost(vi &positions, int level) {
  ll out = 0;
  for (auto elem : positions) {
    int delta = abs(elem - level);
    out += delta * (delta + 1) / 2;
  }
  return out;
}

int main() {
  vi positions;
  string l;
  getline(cin, l);
  stringstream ss(l);
  string item;
  while (getline(ss, item, ','))
    positions.push_back(stoi(item));

  sort(positions.begin(), positions.end());
  ll min_cost = -1;
  double sum = 0;
  for (int i = positions[0]; i < positions[positions.size() - 1]; i++) {
    ll cur_cost = calcCost(positions, i);
    if (min_cost == -1)
      min_cost = cur_cost;
    else
      min_cost = min(min_cost, cur_cost);
  }
  cout << min_cost << endl;
}
