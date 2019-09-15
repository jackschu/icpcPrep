#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
long best_inc(int i, int j, long **best_memo, long **inc_memo, bool **best_pres,
              bool **inc_pres, vector<int> &nums);

long best(int i, int j, long **best_memo, long **inc_memo, bool **best_pres,
          bool **inc_pres, vector<int> &nums) {
  //  printf("b%d %d,", i, j);
  if (best_pres[i][j])
    return best_memo[i][j];
  long out = max(
      i == 0 ? 0
             : best(i - 1, j, best_memo, inc_memo, best_pres, inc_pres, nums),
      best_inc(i, j, best_memo, inc_memo, best_pres, inc_pres, nums));
  best_pres[i][j] = true;
  best_memo[i][j] = out;
  return out;
}

long best_inc(int i, int j, long **best_memo, long **inc_memo, bool **best_pres,
              bool **inc_pres, vector<int> &nums) {
  //  printf("%d %d,", i, j);
  if (inc_pres[i][j])
    return inc_memo[i][j];
  long out = max(j == 0 || i == 0 ? 0
                                  : (best(i - 1, j - 1, best_memo, inc_memo,
                                          best_pres, inc_pres, nums)),
                 i == 0 ? 0
                        : best_inc(i - 1, j, best_memo, inc_memo, best_pres,
                                   inc_pres, nums));
  out += nums[i];
  inc_pres[i][j] = true;
  inc_memo[i][j] = out;
  return out;
}

long **makelong(int n, int k) {
  long **a = new long *[n];
  for (int i = 0; i < n; ++i)
    a[i] = new long[k];
  return a;
}

bool **makebool(int n, int k) {
  bool **a = new bool *[n];
  for (int i = 0; i < n; ++i)
    a[i] = new bool[k]();
  return a;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums;
  nums.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(nums));

  long **best_memo = makelong(n, k);
  long **inc_memo = makelong(n, k);
  bool **best_pres = makebool(n, k);
  bool **inc_pres = makebool(n, k);
  long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
    inc_pres[i][i] = true;
    best_pres[i][i] = true;
    best_memo[i][i] = sum;
    inc_memo[i][i] = sum;
  }
  //  for (int i = 0; i < n; i++)
  //cout<<  best(i, 0, best_memo, inc_memo, best_pres, inc_pres, nums)<<endl;

  cout << best(n - 1, k - 1, best_memo, inc_memo, best_pres, inc_pres, nums)
       << endl;
}
