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
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int tc;
  cin >> tc;
  for(int ic = 0; ic < tc;ic++){
    int out = 0;
    int n;
    cin >>n;
    vi nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    for(int i = 1; i < n; i++){
      int cur= nums[i];
      for(int j = 0; j < i; j++){
	if(nums[j] <= cur) out++;
      }
    }
    cout << out << endl;
  }

}
