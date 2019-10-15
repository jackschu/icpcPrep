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

set<int> targs;
vector<int> nums;
int n;

bool run(int c = 0) {
  if (c >= n)
    return false;
  int guess = nums[c];
  if (targs.find(guess) != targs.end())
    return true;
  vi add;

  for (auto elem : targs) {
    int nxt = elem - guess;
    if (nxt > 0)
      add.push_back(nxt);
  }
  for(auto elem: add){
    targs.insert(elem);
  }
  return run(c+1);
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    targs.clear();
    nums.clear();
    int targ;
    cin >> targ;
    targs.insert(targ);
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums.push_back(x);
    }
    cout << (targ == 0 || run() ? "YES" : "NO") << endl;
  }
}
