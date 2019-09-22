#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &nums){
  for (auto elem: nums){
    printf("%d ", elem);
  }
  printf("\n");
}

int main(){
  vector<int> nums;
  nums.reserve(5);
  copy_n(istream_iterator<int>(cin), 5, back_inserter(nums));
  do {
    for(int i = 0; i < 4; i++){
      if (nums[i] > nums[i+1]){
      int temp = nums[i+1];
      nums[i+1] = nums[i];
      nums[i] = temp;
      print_vec(nums);
      }
    }
  }while(!is_sorted(nums.begin(), nums.end()));
}
