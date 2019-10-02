#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    list<int> l;
    int n = s.size();
    auto iter = l.begin();
    for (int i = 0; i < n; i++) {
      if (s[i] == '[') {
        iter = l.begin();
      } else if (s[i] == ']') {
        iter = l.end();
      } else {
        iter = l.insert(iter, s[i]);
        iter++;
      }
    }
    string out(l.begin(), l.end());
    cout << out << endl;
  }
}
