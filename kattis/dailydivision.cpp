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
#define LSOne(S) (S & (-S))
class FenwickTree {
private:
  vector<long> ft;
  // recall that vi is: typedef vector<long> vi;
public:
  FenwickTree(long n) { ft.assign(n + 1, 0); }
  // init n + 1 zeroes
  long rsq(long b) {
    // returns RSQ(1, b)
    long sum = 0;
    for (; b; b -= LSOne(b))
      sum += ft[b];
    return sum;
  }
  // note: LSOne(S) (S & (-S))
  long rsq(long a, long b) {
    // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
  }
  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(long k, long v) {
    // note: n = ft.size() - 1
    for (; k < (long)ft.size(); k += LSOne(k))
      ft[k] += v;
  }
};

long try_it(FenwickTree &ft, long n, vi &nums, long guess) {
  long left = ft.rsq(guess) - nums[guess - 1];
  long right = ft.rsq(n) - ft.rsq(guess);
  long half = nums[guess - 1] / 2;
  left += half;
  right += half;
  if (nums[guess - 1] % 2 == 1) {
    if (left < right) {
      left++;
    } else {
      right++;
    }
  }
  return left - right;
}

long best(FenwickTree &ft, long n, vi &nums) {
  long high = n;
  long low = 1;
  long old_guess = -1;
  long best_guess = -1;
  long best_diff = ft.rsq(n);
  long old_diff = -1;
  while (true) {
    long guess = (high + low + 1) / 2;
    if (old_guess == guess) {
      if (best_guess == -1) {
        best_diff = old_diff;
        best_guess = guess;
      }
      break;
    }
    old_guess = guess;
    long diff = try_it(ft, n, nums, guess);
    old_diff = diff;
    if (diff > 0) {
      high = guess;
      if (abs(diff) < best_diff) {
        best_diff = abs(diff);
        best_guess = guess;
      }
    } else if (diff < 0) {
      low = guess;
      if (abs(diff) < best_diff) {
        best_diff = abs(diff);
        best_guess = guess;
      }
    } else {
      best_diff = diff;
      best_guess = guess;
      break;
    }
    if (high == low) {
      if (best_guess == -1) {
        best_diff = diff;
        best_guess = guess;
      }
      break;
    }
  }
  long guess = best_guess;
  while (guess > 1) {
    long nxt_guess = guess - 1;
    long diff = try_it(ft, n, nums, nxt_guess);
    if (abs(diff) > best_diff) {
      return guess;
    }
    guess = nxt_guess;
  }
  return guess;
}

int main() {
  long n, m;
  cin >> n >> m;
  FenwickTree ft(n);
  vi nums;
  nums.reserve(n);
  copy_n(istream_iterator<long>(cin), n, back_inserter(nums));
  for (long i = 0; i < n; i++) {
    ft.adjust(i + 1, nums[i]);
  }
  // cout << best(ft, n, nums) << endl;
  // return 0;
  for (long i = 0; i < m; i++) {

    long idx, v;
    cin >> idx >> v;
    idx++;
    long adj = v - nums[idx - 1]; // val = nums + adj, adj = val-nums
    ft.adjust(idx, adj);
    nums[idx - 1] = v;

    long out = best(ft, n, nums);
    cout << out - 1 << endl;
  }
}
