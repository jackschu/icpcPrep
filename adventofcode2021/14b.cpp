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
map<pair<pair<char, char>, int>, vector<long long>> memo_count;

struct Pair {
  char first, second;
  int iter = 0;
  vector<Pair *> results;

  Pair(char first, char second)
      : first(first), second(second), iter(0), results({}) {}

  void print() {
    printf("iter %d %c,%c with size %d\n", this->iter, this->first,
           this->second, (int)this->results.size());
  }

  vector<long long> getOccurrences(bool print_last = true) {
    if (!print_last) {
      auto search = make_pair(make_pair(this->first, this->second), this->iter);

      auto found = memo_count.find(search);
      if (found != memo_count.end()) {
        return found->second;
      }
    }

    vector<long long> out(26, 0);
    if (results.size() == 0)
      out[first - 'A']++;

    for (auto child : results) {
      auto child_ct = child->getOccurrences(false);
      for (int i = 0; i < 26; i++)
        out[i] += child_ct[i];
    }

    if (print_last)
      out[second - 'A']++;

    if (!print_last) {
      auto search = make_pair(make_pair(this->first, this->second), this->iter);
      memo_count.insert(make_pair(search, out));
    }
    return out;
  }

  void printFull(bool print_last = true) {
    if (results.size() == 0)
      cout << first;

    for (auto child : results) {
      if (child == this) {
        cout << "fail " << results[0] << " " << results[1] << " ";
        this->print();
        return;
      }

      child->printFull(false);
    }

    if (print_last)
      cout << second << endl;
  }
};

map<pair<pair<char, char>, int>, Pair *> memo;
map<pair<char, char>, char> rules;

Pair *tick(Pair *cur) {
  auto search = make_pair(make_pair(cur->first, cur->second), cur->iter + 1);

  auto found = memo.find(search);
  if (found != memo.end())
    return found->second;

  auto out = new Pair(cur->first, cur->second);
  out->iter = cur->iter + 1;

  if (cur->iter == 0) {
    auto found = rules.find(make_pair(cur->first, cur->second));
    if (found != rules.end()) {
      out->results.push_back(new Pair(cur->first, found->second));
      out->results.push_back(new Pair(found->second, cur->second));
    }
  } else {
    for (auto elem : cur->results)
      out->results.push_back(tick(elem));
  }
  auto to_memo = make_pair(make_pair(out->first, out->second), out->iter);
  memo.insert(make_pair(to_memo, out));
  return out;
}

int main() {
  string input;
  getline(cin, input);
  string l;
  // discard empty line
  getline(cin, l);

  while (getline(cin, l)) {
    char first = l[0], second = l[1], result = l[6];
    rules.insert(make_pair(make_pair(first, second), result));
  }
  vector<long long> occurrence(26, 0);

  for (int i = 1; i < input.size(); i++) {
    auto start = new Pair(input[i - 1], input[i]);

    for (int i = 0; i < 40; i++)
      start = tick(start);

    auto new_occurrence = start->getOccurrences(i == input.size() - 1);

    for (int i = 0; i < 26; i++) {
      occurrence[i] += new_occurrence[i];
    }
  }
  long long high = 0, low = 0;
  for (auto elem : occurrence) {
    if (low == 0)
      low = elem;
    if (elem != 0)
      low = low < elem ? low : elem;
    high = high > elem ? high : elem;
  }
  cout << high - low << endl;
}
