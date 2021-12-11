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

pair<bool, char> firstIllegalChar(const string &l) {
  map<char, char> pairs = {make_pair('(', ')'), make_pair('[', ']'),
                           make_pair('{', '}'), make_pair('<', '>')};
  stack<char> open_chars;

  for (auto cur : l) {
    auto found_pair = pairs.find(cur);
    if (found_pair != pairs.end()) {
      open_chars.push(cur);
      continue;
    }
    char top = open_chars.empty() ? 'x' : open_chars.top();
    found_pair = pairs.find(top);
    if (cur != found_pair->second)
      return make_pair(true, cur);
    open_chars.pop();
  }
  return make_pair(false, 'x');
}

int main() {
  map<char, int> points = {make_pair(')', 3), make_pair(']', 57),
                           make_pair('}', 1197), make_pair('>', 25137)};
  string l;
  ll out = 0;
  while (getline(cin, l)) {
    auto found_char_pair = firstIllegalChar(l);
    if (!found_char_pair.first)
      continue;
    out += points.find(found_char_pair.second)->second;
  }
  cout << out << endl;
}
