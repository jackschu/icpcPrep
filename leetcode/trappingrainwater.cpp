#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int trappingRainWater(vi &height);

int main() {
  vi ans9{4, 2, 0, 3, 2, 5};
  vi ans1{4, 2, 3};
  vi ans1a{3, 2, 4};
  vi ans1b{5, 4, 1, 2};
  vi ans6{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vi ans0{1};
  vi ans02{};
  vi ans03{4, 4, 4, 7, 1, 0};
  vi ans26{0, 1, 2, 0, 3, 0, 1, 2, 0, 0, 4, 2, 1, 2, 5, 0, 1, 2, 0, 2};
  cout << trappingRainWater(ans9) << endl;
  cout << trappingRainWater(ans1) << endl;
  cout << trappingRainWater(ans1a) << endl;
  cout << trappingRainWater(ans1b) << endl;
  cout << trappingRainWater(ans6) << endl;
  cout << trappingRainWater(ans0) << endl;
  cout << trappingRainWater(ans02) << endl;
  cout << trappingRainWater(ans03) << endl;
  cout << trappingRainWater(ans26) << endl;
}

// key idea: you can add water if theres a wall ANYWHERE on the left and right
int trappingRainWaterFast(vi &height) {
  int out = 0;
  int n = height.size();
  if (n == 0)
    return 0;
  int left = 0;
  int right = n - 1;
  int high_left = height[0];
  int high_right = height[n - 1];

  bool moving_from_left = high_left < high_right;

  while (left < right) {
    int cur_idx;
    int *high_height;
    int *high_other;
    if (moving_from_left) {
      cur_idx = ++left;
      high_height = &high_left;
      high_other = &high_right;
    } else {
      cur_idx = --right;
      high_height = &high_right;
      high_other = &high_left;
    }

    int cur_height = height[cur_idx];
    if (cur_height > *high_height)
      *high_height = cur_height;
    else
      out += max(0, min(high_left, high_right) - cur_height);

    if (*high_other < *high_height)
      moving_from_left = !moving_from_left;
  }
  return out;
}

int trappingRainWater(vi &height) {
  int n = height.size();
  if (n == 0)
    return 0;
  int mx = *max_element(height.begin(), height.end());

  int out = 0;
  for (int i = mx; i > 0; i--) {
    bool seen_leftwall = false;
    int could_add = 0;
    for (int j = 0; j < n; j++) {
      bool on_wall = height[j] >= i;
      if (on_wall) {
        if (seen_leftwall)
          out += could_add;

        could_add = 0;
        seen_leftwall = true;
      } else
        could_add++;
    }
  }
  return out;
}
