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

void printStack(stack<char> chars) {
  while (!chars.empty()) {
    cout << chars.top();
    chars.pop();
  }
  cout << endl;
}

/**
 * returns empty vec if not completable
 */
vi getCompletionPoints(const string &l) {
  map<char, char> pairs = {make_pair('(', ')'), make_pair('[', ']'),
                           make_pair('{', '}'), make_pair('<', '>')};
  map<char, int> points = {make_pair('(', 1), make_pair('[', 2),
                           make_pair('{', 3), make_pair('<', 4)};

  stack<char> open_chars;

  for (auto cur : l) {
    DEBUG printStack(open_chars);
    auto found_pair = pairs.find(cur);
    if (found_pair != pairs.end()) {
      open_chars.push(cur);
      continue;
    }
    char top = open_chars.empty() ? 'x' : open_chars.top();
    found_pair = pairs.find(top);
    if (cur != found_pair->second)
      return {};
    open_chars.pop();
  }
  vi out;
  while (!open_chars.empty()) {
    char top = open_chars.top();
    int val = points.find(top)->second;
    out.push_back(val);
    open_chars.pop();
  }

  return out;
}

int main() {
  string l;
  vector<ll> scores;
  while (getline(cin, l)) {
    auto completion = getCompletionPoints(l);
    if (completion.size() == 0)
      continue;
    ll score = 0;
    for (auto elem : completion) {
      score *= 5;
      score += elem;
    }
    scores.push_back(score);
  }
  sort(scores.begin(), scores.end());
  cout << scores[scores.size() / 2] << endl;
}
