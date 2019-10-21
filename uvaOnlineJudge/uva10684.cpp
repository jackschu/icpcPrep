#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
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

int main() {
  int n;
  cin >> n;
  while (n) {
    vi nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    long sum = 0;
    long mx = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (sum < 0)
        sum = 0;
      mx = max(sum, mx);
    }
    if (mx)
      printf("The maximum winning streak is %ld.\n", mx);
    else
      cout << "Losing streak." << endl;
    cin >> n;
  }
}
