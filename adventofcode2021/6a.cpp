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
  deque<ll> fish(9, 0);
  string l;
  getline(cin, l);
  stringstream ss(l);
  string item;
  while (getline(ss, item, ','))
    fish[stoi(item)]++;

  int days = 80;
  for (int i = 0; i < days; i++) {
    ll spawning = fish.front();
    fish.pop_front();
    fish.push_back(spawning);
    fish[6] += spawning;
  }

  ll out = 0;
  for (auto elem : fish)
    out += elem;
  cout << out << endl;
}
