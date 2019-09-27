#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  int TC;
  cin >> TC;
  for(int i = 0; i < TC; i++){
    int n;
    cin >>n;
    vector<int> nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    int out = *max_element(nums.begin(), nums.end());
    printf("Case %d: %d\n", i+1, out);
  }
}
