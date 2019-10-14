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
  int k;
  cin >> k;
  bool first = true;
  while (k) {
    if(!first) cout << endl;
    first = false;
    vi nums;
    nums.reserve(k);
    copy_n(istream_iterator<int>(cin), k, back_inserter(nums));
    for(int a = 0; a < k-5; a++)
      for(int b = a+1; b < k-4; b++)
	for(int c = b+1; c < k-3; c++)
	  for(int d = c+1; d < k-2; d++)
	    for(int e = d+1; e < k-1; e++)
	      for(int f = e+1; f < k; f++)
		printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c], nums[d], nums[e], nums[f]);
    cin >> k;
  }
}
