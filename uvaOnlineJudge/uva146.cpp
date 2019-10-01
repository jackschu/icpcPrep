#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  string s;
  getline(cin, s);
  while (s != "#") {
    if (next_permutation(s.begin(), s.end())) {
      cout << s << endl;
    } else {
      cout << "No Successor"<<endl;
    }

    getline(cin, s);
  }
}
