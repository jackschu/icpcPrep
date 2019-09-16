#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n < 3)
      return {};
    vector<vector<int>> out;
    for (int i = 0; i < n-2; i++) {
      if (nums[i] > 0 ) break;
      if (i != 0 && nums[i] == nums[i-1]) continue;
      int target = -nums[i];
      int left = i+1;
      int right = n-1;
      while(left < right) { 
	if(nums[left] + nums[right] == target){
	  vector<int> sol;
	  sol.push_back(nums[left]);
	  sol.push_back(nums[right]);
	  sol.push_back(-target);
	  out.push_back(sol);
	  while(left < right && nums[left+1] == nums[left]) left++;
	  while(left < right && nums[right-1] == nums[right]) right--;
	  left++;
	  right--;
	} else if (nums[left] + nums[right] < target) left++;
	else right--;
      }
    }
    return out;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  Solution a;
  auto output = a.threeSum(nums);
  for (auto vec : output) {
    for (auto elem : vec) {
      printf("%d ", elem);
    }
    cout << endl;
  }
}
