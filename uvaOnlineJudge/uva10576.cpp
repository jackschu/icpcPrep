#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  unsigned long s, d;
  while (cin >> s >> d) {
    long mx = -1;
    long guess = 0;
    while (!(guess & 1 << 12)) {
      long running_sum = 0;
      long sum = 0;
      bool fail = false;
      for (int i = 0; i < 12; i++) {
        bool add = guess & 1 << i;
        sum += add ? s : -d;
        running_sum += add ? s : -d;
        if (i - 4 >= 0) {
          if (running_sum >= 0) {
            fail = true;
            break;
          }
          // cout << "heck"<<endl;
          bool sub = guess & 1 << (i - 4);
          running_sum -= sub ? s : -d;
        }
      }

      if (!fail && sum > mx) {
        mx = sum;
      }
      guess++;
    }
    if (mx == -1) {
      cout << "Deficit" << endl;
    } else {
      cout << mx << endl;
    }
  }
}
