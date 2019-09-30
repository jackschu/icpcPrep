#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    bool *check = new bool[n]();
    for (int i = 1; i < n; i++) {
      int x = abs(nums[i - 1] - nums[i]);
      if (x < n)
        check[x] = true;
    }
    bool out = true;
    for (int i = 1; i < n; i++)
      out &= check[i];
    if (out)
      cout << "Jolly" << endl;
    else
      cout << "Not jolly" << endl;
    delete[] check;
  }
}
