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
vi nums;
int n, m;
bool run(int c) {
  int sz = nums.size();
  int used = 0;
  int contains = 0;
  for (int i = 0; i < sz && used < m; i++) {
    if (contains + nums[i] > c) {
      contains = nums[i];
      used++;
    } else {
      contains += nums[i];
    }
  }
  return used != m;
}
int main() {

  while (cin >> n >> m) {
    // cout << " running " << endl;
    nums.clear();
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    int high = 1e9;
    int low = *max_element(nums.begin(), nums.end());
    int guess;
    int mn = 1e9 + 1;
    while (high >= low) {
      guess = (high + low) / 2;
      bool good = run(guess);
      // printf("good %d guess %d   h %d l %d\n", int(good), guess, high, low);
      if (good) {
        mn = min(mn, guess);
        high = guess-1;
      } else {
        low = guess+1;
      }
    }
    cout << mn << endl;
  }
}
