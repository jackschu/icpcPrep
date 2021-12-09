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

void printVec(vi &s) {
  for (auto elem : s)
    cout << elem << ", ";
  cout << endl;
}

void printTranslation(vi &s) {
  for (int i = 0; i < 7; i++)
    printf(" %c->%c,", char(i + 'a'), char(s[i] + 'a'));
  cout << endl;
}

void printSet(set<char> &s) {
  for (auto elem : s)
    cout << elem << ",";
  cout << endl;
}

set<char> toSet(string &s) {
  set<char> out;
  for (auto elem : s)
    out.insert(elem);
  return out;
}

/**
 * constructs a mapping printable via printTranslation using the following
 * schema the number 1 uses 2 segments the number 7 uses 3 segments the number 4
 * uses 4 segments
 *
 * a -> segment that appears in 7 but not 1
 * b -> 6x occurrence
 * c -> 8x occurrence but not a
 * d -> 7x occurrence but does appear in 4
 * e -> 4x occurrence
 * f -> 9x occurrence
 * g -> 7x occurrence but does not appear in 4
 */
vi getTranslation(vector<string> &input) {
  vi occurrence(7, 0);
  vi translation(7, -1);
  set<char> seven_enc, one_enc, four_enc;
  for (auto &elem : input) {
    if (elem.size() == 3)
      seven_enc = toSet(elem);
    if (elem.size() == 2)
      one_enc = toSet(elem);
    if (elem.size() == 4)
      four_enc = toSet(elem);
    for (auto one_char : elem)
      occurrence[one_char - 'a']++;
  }

  vector<char> a_candidates;
  set_difference(seven_enc.begin(), seven_enc.end(), one_enc.begin(),
                 one_enc.end(), back_inserter(a_candidates));
  translation[0] = a_candidates[0] - 'a';
  DEBUG printVec(occurrence);
  for (int i = 0; i < 7; i++) {
    if (occurrence[i] == 6)
      translation['b' - 'a'] = i;
    if (occurrence[i] == 8 && i != translation[0])
      translation['c' - 'a'] = i;
    if (occurrence[i] == 7 && four_enc.find(i + 'a') != four_enc.end())
      translation['d' - 'a'] = i;
    if (occurrence[i] == 4)
      translation['e' - 'a'] = i;
    if (occurrence[i] == 9)
      translation['f' - 'a'] = i;
    if (occurrence[i] == 7 && four_enc.find(i + 'a') == four_enc.end())
      translation['g' - 'a'] = i;
  }
  DEBUG printTranslation(translation);
  vi rev_translation(7, -1);
  for (int i = 0; i < 7; i++)
    rev_translation[translation[i]] = i;
  return rev_translation;
}

int main() {
  string l;
  ll out = 0;
  vector<set<char>> decoder = {
      {'a', 'b', 'c', 'e', 'f', 'g'},
      {'c', 'f'},
      {'a', 'c', 'd', 'e', 'g'},
      {'a', 'c', 'd', 'f', 'g'},
      {'b', 'c', 'd', 'f'},
      {'a', 'b', 'd', 'f', 'g'},
      {'a', 'b', 'd', 'e', 'f', 'g'},
      {'a', 'c', 'f'},
      {'a', 'b', 'c', 'd', 'e', 'f', 'g'},
      {'a', 'b', 'c', 'd', 'f', 'g'},
  };

  while (getline(cin, l)) {
    string elem;
    stringstream ss(l);
    vector<string> hints;

    for (int i = 0; i < 10; i++) {
      ss >> elem;
      hints.push_back(elem);
    }
    vi translation = getTranslation(hints);
    // discard pipe separator
    ss >> elem;
    int line_out = 0;
    int pow = 1000;
    for (int i = 0; i < 4; i++) {
      ss >> elem;
      set<char> current;
      for (auto one_char : elem)
        current.insert(translation[one_char - 'a'] + 'a');
      for (int i = 0; i < 10; i++)
        if (current == decoder[i])
          line_out += pow * i;

      pow /= 10;
    }
    out += line_out;
  }
  cout << out << endl;
}
