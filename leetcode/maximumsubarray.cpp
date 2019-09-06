#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int val = nums[0];
    int max = val;
    for (int i = 1; i < n; i++) {
      // if the incoming number is better than all prev, restart
      if (nums[i] > val && val < 0) {
        val = nums[i];
      } else {
        val += nums[i];
      }
      max = std::max(val, max);
    }
    return max;
  }
};

// assume length of vec followed by vec
int main() {
  int n;
  cin >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  Solution a;
  int output = a.maxSubArray(nums);
  cout << output << endl;
}
