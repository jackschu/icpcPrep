#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

const unsigned long N = 10e5 + 1;
bool set_interval(int start, int stop, bitset<N> *b) {
  for (int i = start; i < stop && i <= 10e5; i++) {
    if (b->test(i))
      return false;
    b->set(i);
  }
  return true;
}

bool run_case(int n, int m) {
  bitset<N> *b = new bitset<N>();
  vector<int> ns;
  if (n > 0) {
    ns.reserve(n * 2);
    copy_n(istream_iterator<int>(cin), n * 2, back_inserter(ns));
  }
  vector<int> ms;
  if (m > 0) {
    ms.reserve(m * 3);
    copy_n(istream_iterator<int>(cin), m * 3, back_inserter(ms));
  }
  for (int nct = 0; nct < n; nct++) {
    int st = ns[nct * 2];
    int sp = ns[nct * 2 + 1];
    if (!set_interval(st, sp, b)) {
      delete b;
      return false;
    }
  }

  for (int mct = 0; mct < m; mct++) {
    int st = ms[mct * 3];
    int sp = ms[mct * 3 + 1];
    int repeat = ms[mct * 3 + 2];
    for (int i = 0; i <= 10e5; i += repeat) {
      if (!set_interval(st + i, sp + i, b)) {
        delete b;
        return false;
      }
    }
  }
  delete b;
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  while (n != 0 || m != 0) {
    if (run_case(n, m)) {
      cout << "NO CONFLICT" << endl;
    } else {
      cout << "CONFLICT" << endl;
    }
    cin >> n >> m;
  }
}
