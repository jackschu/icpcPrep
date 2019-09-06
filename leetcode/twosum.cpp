#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> needs;
      for(int i = 0; i < nums.size(); i++){
	auto found = needs.find(nums[i]);
	if (found == needs.end()){
	  needs[target-nums[i]] = i;
	} else {
	  return vector<int> {found->second, i};
	}
      }
      return vector<int> {};
    }
};

// assume target followed by length of vec followed by vec
int main() {
  int target;
  int n;
  cin >> target >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  Solution a;
  vector<int> output = a.twoSum(nums, target);
  if (output.size() == 2){
    printf("[%d, %d]\n", output[0], output[1]);
  } else {
    cout << "incorrect output size\n";
  }
}
