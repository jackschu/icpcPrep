#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> & prices){
    int n = prices.size();
    if (n < 2) return 0;
    int profit = 0;
    int min_buy = prices[0];
    for(int i = 1; i < n; i++){
      profit = max(profit, prices[i] - min_buy);
      min_buy = min(min_buy,prices[i]);
    }
    return profit;
  }
};

int main() {
  
  int n;
  cin >> n;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
  Solution a;
  int output = a.maxProfit(nums);
  cout << output << endl;
}
