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

long arr[20];
int targ;

int main() {

  int n;
  while (cin >> targ) {
    long mn;
    long best_sum;
    mn = LONG_MAX;
    fill_n(arr, 20, 0);
    cin >> n;
    unsigned long guess = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x;
    }
    vi mct;
    vi ct;
    while (!(guess & 1 << n)) {
      long sum = 0;
      ct.clear();
      ct.reserve(20);
      for (int i = 0; i < n; i++) {
        if (guess & 1 << i) {
          sum += arr[i];
          ct.push_back(i);
        }
      }
      long cur = targ - sum;
      if (cur >= 0 &&
          (cur < mn ||
           (cur == mn && lexicographical_compare(ct.begin(), ct.end(),
                                               mct.begin(), mct.end())))) {
        mct = ct;
        mn = cur;
        best_sum = sum;
      }
      guess++;
    }
    int mcn =mct.size();
    for (int i = 0; i < mcn; i++) {
      printf("%ld ", arr[mct[i]]);
    }
    printf("sum:%ld\n", best_sum);
  }
}
