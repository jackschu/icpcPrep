#include <vector>

int findPeakElement(vector<int>& nums, int low = 0, int high = -1) {
      if(high == -1) high = nums.size()-1;
      if(high - low <= 1) return nums[high] < nums[low] ? low : high;
      int middle = (high+low)/2;
      if(middle == 0 || nums[middle-1] > nums[middle])
          return findPeakElement(nums, low, middle-1);
      return findPeakElement(nums, middle, high); 
  }
