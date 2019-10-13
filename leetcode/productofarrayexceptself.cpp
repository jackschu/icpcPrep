#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long> vi;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> l,r,out;
    r.assign(n,0);
    l.assign(n,0);
    out.reserve(n);
    l[0] = 1;
    r[n-1] = 1;
    for(int i = 1; i < n; i++){
      int o = n-i-1;
      r[o] = nums[o+1]*r[o+1];
      l[i] = nums[i-1]*l[i-1];
    }
    for(int i =0; i < n; i++){
      out.push_back(r[i]*l[i]);
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
  vector<int> output = a.productExceptSelf(nums);
  for(auto elem: output){
    cout << elem << " ";
  }
  cout << endl;
}
