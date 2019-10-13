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

struct info {
  int mx, mxl, mxr, vl, vr;
  info()  : mx(1), mxl(1), mxr(1), vl(1), vr(1){}
  info(int i) : mx(1), mxl(1), mxr(1), vl(i), vr(i) {}
};

info merge_info(const info &p1, const info &p2) {
  info i;
  if (p1.vl == p2.vr) {
    i.vl = i.vr = p1.vl;
    i.mxl = i.mxr = i.mx = p1.mx + p2.mx;
  } else if (p1.vl == p2.vl) {
    i.mxl = p1.mx + p2.mxl;
    i.mxr = p2.mxr;
    i.vl = p1.vl;
    i.vr = p2.vr;
    i.mx = max(p2.mx, i.mxl);
  } else if (p1.vr == p2.vr) {
    i.mxr = p2.mx + p1.mxr;
    i.mxl = p1.mxl;
    i.vl = p1.vl;
    i.vr = p2.vr;
    i.mx = max(p1.mx, i.mxr);
  } else if (p1.vr == p2.vl) {
    i.mx = max(max(p1.mx, p2.mx), p1.mxr + p2.mxl);
    i.vl = p1.vl;
    i.mxl = p1.mxl;
    i.vr = p2.vr;
    i.mxr = p2.mxr;
  } else {
    i.mx = max(p1.mx, p2.mx);
    i.vl = p1.vl;
    i.mxl = p1.mxl;
    i.vr = p2.vr;
    i.mxr = p2.mxr;
  }
  return i;
}
class SegmentTree {
  // the segment tree is stored like a heap array
private:
  vi A;
  vector<info> st;
      // recall that vi is: typedef vector<int> vi;
      int n;
  int left(int p) { return p << 1; }
  // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    // O(n)
    if (L == R)
      // as L == R, either one is fine
      st[p] = info(A[L]);
    // store the index
    else {
      // recursively compute the values
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      info p1 = st[left(p)], p2 = st[right(p)];
      st[p] = merge_info(p1, p2);
    }
    DEBUG printf("%d %d %d %d %d\n", L, R, st[p].mx, st[p].vl, st[p].vr);
  }
  info rmq(int p, int L, int R, int i, int j) {
    // O(log n)
    if (i > R || j < L){
      info i;
      i.mx = -1;
      return i; // current segment outside query range
    }
    if (L >= i && R <= j)
      return st[p];
    // inside query range
    // compute the min position in the left and right part of the interval
    info p1 = rmq(left(p), L, (L + R) / 2, i, j);
    info p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if (p1.mx == -1)
      return p2;
    // if we try to access segment outside query
    if (p2.mx == -1)
      return p1;
    // same as above
    return merge_info(p1, p2);
    // as in build routine
  }

public:
  SegmentTree(const vi &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  info rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
  // overloading
};

int main() {
  int n, m;
  cin >> n;
  while (n != 0) {
    cin >> m;
    vi in;
    in.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(in));
    SegmentTree st(in);
    for (int i = 0; i < m; i++) {
      int a,b;
      cin >> a >>b;
      auto got = st.rmq(a-1,b-1);
      cout << got.mx <<endl;
      // cout << got.vl <<endl;
      // cout << got.vr <<endl;

    }
    cin >> n;
  }
}
