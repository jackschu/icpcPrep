#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> combinationSumHelper(vector<int> &nums, int target,
                                         int fm) {
  if (target == 0) return {{}};
  if (target < nums[0]) return {};
  vector<vector<int>> out;
  int n = nums.size();
  for (int i = fm; i < n && nums[i] <= target; i++) {
    auto temp = combinationSumHelper(nums, target - nums[i], i);
    for (auto &elem : temp)
      elem.push_back(nums[i]);
    if (temp.size() != 0) {
      out.insert(out.end(), temp.begin(), temp.end());
    }
  }
  return out;
}

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return combinationSumHelper(candidates, target, 0 );
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  int target;
  cin >> target;
  Solution a;
  auto output = a.combinationSum(nums, target);
  for (auto vec : output) {
    for (auto elem : vec) {
      printf("%d ", elem);
    }
    cout << endl;
  }
}
