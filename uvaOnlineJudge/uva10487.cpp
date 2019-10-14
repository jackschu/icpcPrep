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
  int n;
  cin >> n;
  int tc =0;
  while (n) {
    tc++;
    printf("Case %d:\n",tc);
    int out = 0;
    vi nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    sort(nums.begin(), nums.end());
    int q; cin>>q;
    for (int i = 0; i < q; i++) {
      int targ;
      cin >> targ;
      int l = 0;
      int r = n - 1;
      int best = nums[0]+nums[1] - targ;
      while (l < r) {
	int cur = nums[l]+nums[r] - targ;
	if(abs(cur) < abs(best)){
	  best = cur;
	}
	if(cur < 0){
	  l++;
	} else if (cur >0)
	  r--;
	else
	  break;
      }
    printf("Closest sum to %d is %d.\n", targ, best+targ);
    }
    cin >> n;
  }
}
