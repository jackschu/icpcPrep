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
  int n;
  cin >> n;
  while (n) {

    int a1;
    cin >> a1;
    while (a1) {
      vector<int> targ;
      targ.reserve(n);
      targ.push_back(a1);
      queue<int> incoming;
      for (int i = 1; i <= n; i++)
        incoming.push(i);

      stack<int> station;
      copy_n(istream_iterator<int>(cin), n - 1, back_inserter(targ));
      bool win = true;
      for (int i = 0; i < n; i++) {
        int cur = targ[i];
        bool good = false;
        while (true) {
          if (!station.empty()) {
            int inc_s = station.top();
            if (inc_s == cur) {
              station.pop();
              good = true;
              break;
            }
          }
          if (!incoming.empty()) {
            int inc_a = incoming.front();
            incoming.pop();
            if (inc_a == cur) {
              good = true;
              break;
            } else {
              station.push(inc_a);
            }
          }
          if (incoming.empty())
            break;
        }
        if (!good) {
          win = false;
          break;
        }
      }
      cout << (win ? "Yes" : "No") << endl;

      cin >> a1;
    }
    cout << endl;
    cin >> n;
  }
}
