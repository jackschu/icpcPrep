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
  string l;
  int out = 0;
  set<int> uniques = {2, 3, 4, 7};
  while (getline(cin, l)) {
    string elem;
    stringstream ss(l);
    for (int i = 0; i < 11; i++)
      ss >> elem;
    for (int i = 0; i < 4; i++) {
      ss >> elem;
      if (uniques.find(elem.length()) != uniques.end())
        out++;
    }
  }
  cout << out << endl;
}
