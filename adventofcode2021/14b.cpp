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
map<pair<char, char>, char> rules;

vector<long long> getOccurrences(char first, char second, int iter,
                                 bool print_last = true) {
  if (!print_last) {
    auto search = make_pair(make_pair(first, second), iter);

    auto found = memo_count.find(search);
    if (found != memo_count.end()) {
      return found->second;
    }
  }

  vector<long long> out(26, 0);
  if (iter == 0) {
    out[first - 'A']++;
  } else {
    auto found = rules.find(make_pair(first, second));
    if (found != rules.end()) {
      auto child_ct = getOccurrences(first, found->second, iter - 1, false);
      for (int i = 0; i < 26; i++)
        out[i] += child_ct[i];

      child_ct = getOccurrences(found->second, second, iter - 1, false);
      for (int i = 0; i < 26; i++)
        out[i] += child_ct[i];
    }
  }

  if (print_last)
    out[second - 'A']++;

  if (!print_last) {
    auto search = make_pair(make_pair(first, second), iter);
    memo_count.insert(make_pair(search, out));
  }
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
    auto new_occurrence =
        getOccurrences(input[i - 1], input[i], 40, i == input.size() - 1);

    for (int i = 0; i < 26; i++)
      occurrence[i] += new_occurrence[i];
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
