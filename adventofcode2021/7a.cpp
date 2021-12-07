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
  vi positions;
  string l;
  getline(cin, l);
  stringstream ss(l);
  string item;
  while (getline(ss, item, ','))
    positions.push_back(stoi(item));

  sort(positions.begin(), positions.end());
  int median = positions[positions.size() / 2];
  ll out = 0;
  for (auto elem : positions)
    out += abs(elem - median);
  cout << out << endl;
}
