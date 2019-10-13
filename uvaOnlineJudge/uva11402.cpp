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
  int v, s = -1;
  int i = 0;
  info(int v) : v(v) {}
};

class SegmentTree {
  // the segment tree is stored like a heap array
private:
  string A;
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
      st[p] = A[L] == '1' ? info(1) : info(0);
    // store the index
    else {
      // recursively compute the values
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)].v, p2 = st[right(p)].v;
      st[p] = info(p1 + p2);
    }
  }

  int rmq(int p, int L, int R, int i, int j) {
    // O(log n)
    if (i > R || j < L) {
      return 0;
    }
    if (i >= L && j <= R) {
      if (st[p].s ==0) {return 0;}
      if (st[p].s ==1) {
	return j-i+1;
      }
    }
    if (L >= i && R <= j) {
      prop(p, L, R);

      return st[p].v;
    }
    prop(p, L, R);
    // inside query range
    // compute the min position in the left and right part of the interval
    int hf=  (L+R)/2;
    int p1 = rmq(left(p), L, hf, i, min(j, hf));
    int p2 = rmq(right(p), hf+1, R, max(i, hf+1), j);
    return p1 + p2;
    // as in build routine
  }

  void change(int p, int L, int R, int v) {
    DEBUG printf("%d %d %d\n", L, R ,v);
    if (p >= 4 * n)
      return;
    if (v == -1)
      return;
    int val;
    int cur = v;
    switch (cur) {
    case -1:
      val = st[p].v;
      break;
    case 0:
      val = 0;
      break;
    case 1:
      val = R - L + 1;
      break;
    case 2:
      val = R - L + 1 - st[p].v;
      break;
    }

    st[p].v = val;
    int l = left(p);
    int r = right(p);
    if (v == 0 || v == 1) {
      if (l < 4 * n)
        st[l].s = v;
      if (r < 4 * n)
        st[r].s = v;
    } else if (v == 2) {
      if (l < 4 * n) {
        int pend = st[l].s;
        int in;
        if (pend == 2)
          in = -1;
        if (pend == 1)
          in = 0;
        if (pend == -1)
          in = 2;
        if (pend == 0)
          in = 1;
        st[l].s = in;
      }
      if (r < 4 * n) {
        int pend = st[r].s;
        int in;
        if (pend == 2)
          in = -1;
        if (pend == 1)
          in = 0;
        if (pend == -1)
          in = 2;
        if (pend == 0)
          in = 1;
        st[r].s = in;
      }
    }
  }
  void prop(int p, int L, int R) {
    if (st[p].s == -1)
      return;
    change(p, L, R, st[p].s);
    st[p].s = -1;
  }
  int update(int p, int L, int R, int i, int j, int v) {
    // O(log n)
    if(p>=4*n)return 0;
    prop(p, L, R);
    if (i > R || j < L) {
      return st[p].v;
    }
    if (L >= i && R <= j) {
      change(p, L, R, v);
      return st[p].v;
    }
    // inside query range
    // compute the min position in the left and right part of the interval
    int p1 = update(left(p), L, (L + R) / 2, i, j,v);
    int p2 = update(right(p), (L + R) / 2 + 1, R, i, j,v);
    //if(p==2) cout << p1 <<"upd"<<p2<<endl;
    st[p].v =p1+p2;
    return p1 + p2;
    // as in build routine
  }
public:
  SegmentTree(const string &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
  int update(int i, int j, int v) { return update(1, 0, n - 1, i, j, v); }
  // overloading
};

int main() {
  int tc;
  cin >> tc;
  for (int run = 0; run < tc; run++) {
    printf("Case %d:\n", run + 1);
    int m;
    cin >> m;
    vi A;
    stringstream ss;
    for (int i = 0; i < m; i++) {
      int reps;
      cin >> reps;
      string s;
      cin.ignore();
      getline(cin, s);
      for (int j = 0; j < reps; j++) {
        ss << s;
      }
    }
    string out;
    ss >> out;
    SegmentTree st(out);
    int cmds;
    cin >> cmds;
    int qct = 1;
    for (int i = 0; i < cmds; i++) {
      char cmd;
      int a, b;
      cin >> cmd >> a >> b;
      for (int j = 0; j < out.size(); j++) {
        DEBUG cout << st.rmq(j, j);
      }
      DEBUG cout << endl;
      DEBUG cout << st.rmq(0, 1);
      DEBUG cout << st.rmq(2, 3);
      DEBUG cout << endl;
      if (cmd == 'S') {

        printf("Q%d: %d\n", qct, st.rmq(a, b));
        qct++;
      } else if (cmd == 'I') {
        st.update(a, b, 2);
      } else if (cmd == 'F') {
        st.update(a, b, 1);
      } else if (cmd == 'E') {
        st.update(a, b, 0);
      }
      // st.update(a,b,cmd);
    }
  }
}
