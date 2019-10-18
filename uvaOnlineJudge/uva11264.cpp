#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
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
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int smart(const vector<long> &nums,int n){
  long sum = 0;
  int ct =1;
  for(int i = 0; i < n-1; i++){
    long x = nums[i];
    if(sum+x < nums[i+1]){
      DEBUG cout << "adding " <<x << endl;
      ct++;
      sum+= x;
    }
  }
  return ct;
}

int main(){
  int tc;
  cin >> tc;
  for(int ic = 0; ic <tc; ic++){
    int n;
    cin >> n;
    vector<long> nums;
    copy_n(istream_iterator<long> (cin), n, back_inserter(nums));
    cout << smart(nums, n) <<endl;
  }
}
