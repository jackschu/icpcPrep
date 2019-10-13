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

int sign(int x) {
  if (x == 0)
    return 0;
  if (x < 0)
    return -1;
  return 1;
}

class SegmentTree {
  // the segment tree is stored like a heap array
private:
  vi st, A;
  // recall that vi is: typedef vector<int> vi;
  int n;
  int left(int p) { return p << 1; }
  // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    // O(n)
    if (L == R) {
      // as L == R, either one is fine
      st[p] = sign(A[L]);
    }
    // store the index
    else {
      // recursively compute the values
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 * p2;
    }
  }
  int rmq(int p, int L, int R, int i, int j) {
    // O(log n)
    if (i > R || j < L)
      return 1;
    if (L >= i && R <= j)
      return st[p];
    // inside query range
    // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    return p1*p2;
    // as in build routine
  }
  int update(int p, int L, int R, int i, int j, int v) {
    // O(log n)
    if (p>=n*4) return 1;
    if (i > R || j < L)
      return st[p]; // current segment outside query range
    if (L == i && R ==j) {
      st[p] = v;
      return st[p];
    }
    // inside query range
    // compute the min position in the left and right part of the interval
    int p1 = update(left(p), L, (L + R) / 2, i, j,v);
    int p2 = update(right(p), (L + R) / 2 + 1, R, i, j,v);
    st[p] = p1 * p2;
    return st[p];
    // as in build routine
  }

public:
  SegmentTree(const vi &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
  int update(int idx, int v) { return update(1, 0, n - 1, idx, idx, sign(v)); }
  // overloading
};
int main() {
  int N, k;
  bool first = true;
  while (cin >> N >> k) {
    if(!first) cout << endl;
    first = false;
    vi a;
    a.reserve(N);
    copy_n(istream_iterator<int>(cin), N, back_inserter(a));
    SegmentTree st(a);
    for (int i = 0; i < k ; i++) {
      char c;
      int a,b;
      cin>> c>> a >> b;
      if(c == 'C'){
	st.update(a-1,b);
      }else{
	int out =st.rmq(a-1,b-1);
	if(out == 0) cout << out;
	else if(out < 0) cout<< '-';
	else if(out > 0) cout<< '+';
      }
    }
  }
  cout<<endl;
}
