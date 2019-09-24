#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#define DEBUG if (false)
using namespace std;

void rundata(){
  int n, m;
  cin >> n >> m;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));

  vector<int> idx;
  for(int i = 0; i< n; i++){
    if(nums[i] == m)idx.push_back(i);
  }
  int mx = 0;
  for(int j = 0; j < idx.size(); j++){
    int k = idx[j];
    int sum = 0;
    for(int i = k + 1; i < nums.size(); i++){
      if(nums[i] <= m) break;
      sum += nums[i];
    }
    for(int i = k - 1; i >= 0; i--){
      if(nums[i] <= m) break;
      sum += nums[i];
    }
    mx = max(sum, mx);
  }
  cout << mx + m << endl;
    
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    rundata();
  }
}
