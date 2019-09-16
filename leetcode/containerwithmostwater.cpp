#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int i =0;
    int j = n - 1;
    int mx = 0;
    while (i < j) {
      int l = j - i;
      if (height[i] <= height[j]) {
	mx = max(mx, height[i]*l);
        i++;
      } else {
	mx = max(mx, height[j]*l);
        j--;
      }
    }
    return mx;
  }
};

int brutemax(vector<int> &nums){
  int n = nums.size();
  int mx = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      mx = max(mx, (j-i)*min(nums[i], nums[j]));
    }
  }
  return mx;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  Solution a;
  int output = a.maxArea(nums);
  cout << output << endl;
  cout << "enter -1 to run random tests" << endl;
  cin >> n;
  while(if n == -1){
    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), []() -> int {return rand()%100;});
    for(auto elem : v)
      printf("%d,",elem);
    cout << endl;
    if(a.maxArea(v) != brutemax(v)){
      break;
    }
  }
}
