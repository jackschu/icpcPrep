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
int t, n;
int nums[12];
vector<int> ans;
set<map<int,int>> ans_map;
int cur;
map<int,int> cur_map;
void backtrack(int c, int sum) {
  if (sum == t && ans_map.find(cur_map)==ans_map.end()) {
    ans.push_back(cur);
    ans_map.emplace(cur_map);
    //cout << " found  " << cur<<endl;
  }
  if (sum >= t)
    return;
  if (c == n)
    return;
  cur_map[nums[c]]++;
  cur |= 1 << c;
  backtrack(c + 1, sum + nums[c]);
  cur_map[nums[c]]--;
  cur ^= 1 << c;
  backtrack(c + 1, sum);
}

int main() {
  cin >> t >> n;

  while (n) {
    cur = 0;
    ans.clear();
    ans_map.clear();
    cur_map.clear();
    printf("Sums of %d:\n", t);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums[i] = x;
      cur_map[x] = 0;
    }
    sort(nums, nums + n, greater<int>());
    backtrack(0, 0);
    if (ans.empty()) cout << "NONE" <<endl;
    for (auto elem : ans) {
      int i = 0;
      bool first = true;
      while (elem != 0) {
        if ((elem & 1) != 0) {
	  if(!first)
	    cout<< "+";
	  first = false;
	  cout<< nums[i];
        }
        elem >>= 1;
        i++;
      }
      cout << endl;
    }
    cin >> t >> n;
  }
}
