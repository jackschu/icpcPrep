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

int main(){
  int n;
  while(cin >> n){
    vi nums;
    nums.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    sort(nums.begin(), nums.end());
    int targ;
    cin>>targ;
    int mn = INT_MAX;
    int first, second;
    for(int i = 1; i< n; i++){
      if(binary_search(nums.begin(), nums.begin()+i ,targ-nums[i])){
	//printf("%d %d\n", targ-nums[i], nums[i]);
	int cur = abs(targ-nums[i] - nums[i]);
	if(cur < mn){
	  mn = cur;
	  first = targ-nums[i];
	  second = nums[i];
	}
      }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", first, second);
  }
}
