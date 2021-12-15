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
  string input;
  list<char> polymer;
  getline(cin, input);
  for (auto one_char : input)
    polymer.push_back(one_char);

  string l;
  // discard empty line
  getline(cin, l);
  map<pair<char, char>, char> rules;
  while (getline(cin, l)) {
    char first = l[0], second = l[1], result = l[6];
    rules.insert(make_pair(make_pair(first, second), result));
  }

  for (int i = 0; i < 10; i++) {
    auto it = polymer.begin();
    it++;
    auto prev_it = polymer.begin();
    while (it != polymer.end()) {
      auto found = rules.find(make_pair(*prev_it, *it));
      if (found != rules.end())
        polymer.insert(it, found->second);
      prev_it = it;
      it++;
    }
  }

  vi occurence(26, 0);
  for (auto elem : polymer)
    occurence[elem - 'A']++;
  unsigned long long high = 0, low = 0;
  for (auto elem : occurence) {
    if (low == 0)
      low = elem;
    if (elem != 0)
      low = low < elem ? low : elem;
    high = high > elem ? high : elem;
  }
  cout << high - low << endl;
}
